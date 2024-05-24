/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:38:22 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 21:05:14 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

void	init_split_state(t_split_state *state)
{
	state->result = (char **) state->result_buf;
	ft_bzero(state->result, 1024);
	ft_bzero(state->token, 1024);
	state->in_single_quote = 0;
	state->in_double_quote = 0;
	state->token_index = 0;
	state->result_index = 0;
	state->i = 0;
}

void	cleanup_split_state(t_split_state *state)
{
	int	j;

	j = 0;
	while (j < 128)
	{
		if (state->result[j] != NULL)
			free(state->result[j]);
		state->result[j] = NULL;
		j++;
	}
}

void	add_token_if_needed(t_split_state *state)
{
	if (state->token_index != 0)
	{
		state->token[state->token_index] = '\0';
		state->result[state->result_index++] = ft_strdup(state->token);
		state->token_index = 0;
	}
}
