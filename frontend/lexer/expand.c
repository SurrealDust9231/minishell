/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:46:16 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/22 20:08:00 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

int	quote_state(int current_state, int in_other_quote)
{
	if (!in_other_quote)
		return (!current_state);
	return (current_state);
}

void	copy_var_value(char *result, int *result_idx, const char *var_value)
{
	while (*var_value)
		result[(*result_idx)++] = *var_value++;
}

int	variable_expansion(const char *token, int *i, char *result, int *result_idx, t_minsh *minsh)
{
	char	var_name[256];
	int		var_idx;
	char	*var_value;

	var_idx = 0;
	(*i)++;
	while (ft_isalnum(token[*i]) || token[*i] == '_')
		var_name[var_idx++] = token[(*i)++];
	var_name[var_idx] = '\0';
	var_value = ft_envlst_get(minsh->elst, var_name);
	if (var_value)
		copy_var_value(result, result_idx, var_value);
	if (token[*i] != '\0')
		(*i)--;
	return (*i);
}

void	handle_char(t_expantion_context *ctx, t_minsh *minsh)
{
	if (ctx->token[ctx->i] == '\'' && !ctx->in_double_quote)
	{
		ctx->in_single_quote = quote_state(ctx->in_single_quote,
				ctx->in_double_quote);
		ctx->i++;
	}
	else if (ctx->token[ctx->i] == '\"' && !ctx->in_single_quote)
	{
		ctx->in_double_quote = quote_state(ctx->in_double_quote,
				ctx->in_single_quote);
		ctx->i++;
	}
	else if (ctx->token[ctx->i] == '$' && !ctx->in_single_quote
		&& (ctx->in_double_quote || !ft_isspace(ctx->token[ctx->i + 1])))
	{
		ctx->i = variable_expansion(ctx->token, &ctx->i,
				ctx->result, &ctx->result_idx, minsh);
	}
	else
	{
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i];
		ctx->i++;
	}
}

char	*expand_variables(char *token, t_minsh *minsh)
{
	t_expantion_context	ctx;

	ctx.i = 0;
	ctx.result_idx = 0;
	ctx.in_single_quote = 0;
	ctx.in_double_quote = 0;
	ctx.result = malloc(4096);
	ctx.token = token;
	if (!ctx.result)
		return (NULL);
	while (token[ctx.i])
	{
		handle_char(&ctx, minsh);
	}
	ctx.result[ctx.result_idx] = '\0';
	return (ctx.result);
}
