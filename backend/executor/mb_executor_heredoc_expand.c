/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_heredoc_expand.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:51:00 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 14:06:56 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbehe_variable_expansion(const char *token, int *i,
	t_heredoc_rcontext *res_ctx, t_minsh *minsh)
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
		mbehe_copy_var_value(res_ctx->result, res_ctx->result_idx, status_str);
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
		mbehe_copy_var_value(res_ctx->result, res_ctx->result_idx, var_value);
	return (*i);
}

static void	_mbehe_p_q(t_heredoc_context *ctx, \
	t_minsh *minsh, t_heredoc_rcontext *res_ctx)
{
	int	prev_i;

	if (ctx->token[ctx->i] == '\'')
	{
		ctx->in_single_quote = mbehe_quote_state(ctx->in_single_quote,
				ctx->in_double_quote);
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i++];
	}
	else if (ctx->token[ctx->i] == '\"')
	{
		ctx->in_double_quote = mbehe_quote_state(ctx->in_double_quote,
				ctx->in_single_quote);
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i++];
	}
	else if (ctx->token[ctx->i] == '$' && !ctx->in_single_quote
		&& (ctx->in_double_quote || !ft_isspace(ctx->token[ctx->i + 1])))
	{
		prev_i = ctx->i;
		ctx->i = _mbehe_variable_expansion(ctx->token, &ctx->i, res_ctx, minsh);
		if (ctx->i == prev_i)
			ctx->i++;
	}
	else
		ctx->result[ctx->result_idx++] = ctx->token[ctx->i++];
}

static void	_mbehe_handle_char(t_heredoc_context *ctx, t_minsh *minsh)
{
	t_heredoc_rcontext	res_ctx;

	res_ctx.result = ctx->result;
	res_ctx.result_idx = &ctx->result_idx;
	_mbehe_p_q(ctx, minsh, &res_ctx);
}

int	mb_executor_heredoc_expand(char **token, t_minsh *minsh)
{
	t_heredoc_context	ctx;

	ctx.i = 0;
	ctx.result_idx = 0;
	ctx.in_single_quote = 0;
	ctx.in_double_quote = 0;
	ctx.result = malloc(4096);
	ctx.token = *token;
	if (!ctx.result)
		return (-1);
	while (token[ctx.i])
		_mbehe_handle_char(&ctx, minsh);
	ctx.result[ctx.result_idx] = '\0';
	free(*token);
	*token = ctx.result;
	return (0);
}
