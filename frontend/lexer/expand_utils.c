/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:39:59 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/22 21:40:19 by saguayo-         ###   ########.fr       */
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
