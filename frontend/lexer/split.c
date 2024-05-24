/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:42:30 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 21:04:51 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

static void	special_character(t_split_state *state, char current, char *str)
{
	if (ft_isspace(current))
	{
		add_token_if_needed(state);
		while (ft_isspace(str[state->i + 1]))
			state->i++;
	}
	else if (current == '>' || current == '<' || current == '|')
	{
		add_token_if_needed(state);
		if ((current == '>' || current == '<') && str[state->i + 1] == current)
		{
			state->token[state->token_index++] = current;
			state->i++;
		}
		state->token[state->token_index++] = current;
		add_token_if_needed(state);
	}
	else
		state->token[state->token_index++] = current;
}

static void	handle_character(t_split_state *state, char *str)
{
	char	current;

	current = str[state->i];
	if (current == '\'' && !state->in_double_quote)
	{
		state->in_single_quote = !state->in_single_quote;
		state->token[state->token_index++] = current;
	}
	else if (current == '\"' && !state->in_single_quote)
	{
		state->in_double_quote = !state->in_double_quote;
	}
	else if (!state->in_single_quote && !state->in_double_quote)
	{
		special_character(state, current, str);
	}
	else
		state->token[state->token_index++] = current;
}

int	custom_split(char *str, t_split_state *state)
{
	init_split_state(state);
	while (str[state->i])
	{
		handle_character(state, str);
		state->i++;
	}
	if (state->in_double_quote)
	{
		printf("Error: doubles quotes are open.\n");
		cleanup_split_state(state);
		return (-1);
	}
	add_token_if_needed(state);
	return (0);
}
