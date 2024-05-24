/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_heredoc_expand_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:51:00 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 14:07:04 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbehe_quote_state(int current_state, int in_other_quote)
{
	if (!in_other_quote)
		return (!current_state);
	return (current_state);
}

void	mbehe_copy_var_value(char *result, \
	int *result_idx, const char *var_value)
{
	while (*var_value)
		result[(*result_idx)++] = *var_value++;
}
