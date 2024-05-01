/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:38:22 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/01 18:39:22 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

void	init_split_state(t_split_state *state)
{
	state->result = (char **)malloc(128 * sizeof(char *));
	state->token = malloc(1024);
	state->in_single_quote = 0;
	state->in_double_quote = 0;
	state->token_index = 0;
	state->result_index = 0;
	state->i = 0;
}

void	cleanup_split_state(t_split_state *state)
{
	int	j;

	if (state->in_single_quote || state->in_double_quote)
	{
		printf("Syntax error: unmatched quote\n");
		j = 0;
		while (j < state->result_index)
			free(state->result[j++]);
		free(state->result);
		state->result = NULL;
	}
	free(state->token);
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
