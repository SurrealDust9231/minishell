/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:46:16 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 20:31:33 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

int	variable_expansion(const char *token, int *i,
	t_result_context *res_ctx, t_minsh *minsh)
{
	int		var_idx;
	char	var_name[256];
	char	*var_value;
	char	status_str[12];

	var_idx = 0;
	(*i)++;
	if (token[*i] == '?')
	{
		snprintf(status_str, sizeof(status_str), "%d", minsh->status);
		copy_var_value(res_ctx->result, res_ctx->result_idx, status_str);
		(*i)++;
		return (*i);
	}
	while (ft_isalnum(token[*i]) || token[*i] == '_')
	{
		var_name[var_idx++] = token[(*i)++];
	}
	var_name[var_idx] = '\0';
	var_value = ft_envlst_get(minsh->elst, var_name);
	if (var_value)
		copy_var_value(res_ctx->result, res_ctx->result_idx, var_value);
	return (*i);
}

void	p_q(t_expantion_context *ctx, t_minsh *minsh, t_result_context *res_ctx)
{
	int	prev_i;

	if (ctx->token[ctx->i] == '\'')
	{
		ctx->in_single_quote = quote_state(ctx->in_single_quote,
				ctx->in_double_quote);
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i++];
	}
	else if (ctx->token[ctx->i] == '\"')
	{
		ctx->in_double_quote = quote_state(ctx->in_double_quote,
				ctx->in_single_quote);
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i++];
	}
	else if (ctx->token[ctx->i] == '$' && !ctx->in_single_quote
		&& (ctx->in_double_quote || !ft_isspace(ctx->token[ctx->i + 1])))
	{
		prev_i = ctx->i;
		ctx->i = variable_expansion(ctx->token, &ctx->i, res_ctx, minsh);
		if (ctx->i == prev_i)
			ctx->i++;
	}
	else
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i++];
}

void	handle_char(t_expantion_context *ctx, t_minsh *minsh)
{
	t_result_context	res_ctx;

	res_ctx.result = ctx->result;
	res_ctx.result_idx = &ctx->result_idx;
	p_q(ctx, minsh, &res_ctx);
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
		handle_char(&ctx, minsh);
	ctx.result[ctx.result_idx] = '\0';
	return (ctx.result);
}
