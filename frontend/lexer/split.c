/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:42:30 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/01 14:30:47 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

// char	**custom_split(char *str)
// {
// 	char	**result;
// 	char	token[1024];
// 	char	current;
// 	int		in_single_quote;
// 	int		in_double_quote;
// 	int		token_index;
// 	int		result_index;
// 	int		i;
// 	int		j;

// 	in_single_quote = 0;
// 	in_double_quote = 0;
// 	token_index = 0;
// 	result_index = 0;
// 	i = 0;
// 	result = (char **)malloc(128 * sizeof(char *));
// 	if (!result)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		current = str[i];
// 		if (current == '\'' && !in_double_quote)
// 		{
// 			in_single_quote = !in_single_quote;
// 			token[token_index++] = current;
// 			i++;
// 			continue ;
// 		}
// 		if (current == '\"' && !in_single_quote)
// 		{
// 			in_double_quote = !in_double_quote;
// 			token[token_index++] = current;
// 			i++;
// 			continue ;
// 		}
// 		if (!in_single_quote && !in_double_quote)
// 		{
// 			if (ft_isspace(current))
// 			{
// 				if (token_index != 0)
// 				{
// 					token[token_index] = '\0';
// 					result[result_index++] = ft_strdup(token);
// 					token_index = 0;
// 				}
// 				i++;
// 				while (ft_isspace(str[i]))
// 					i++;
// 				continue ;
// 			}
// 			if (current == '>' || current == '<' || current == '|')
// 			{
// 				if (token_index != 0)
// 				{
// 					token[token_index] = '\0';
// 					result[result_index++] = ft_strdup(token);
// 					token_index = 0;
// 				}
// 				if ((current == '>' || current == '<') && str[i + 1] == current)
// 				{
// 					result[result_index++] = ft_strndup(str + i, 2);
// 					i += 2;
// 				}
// 				else
// 				{
// 					result[result_index++] = ft_strndup(str + i, 1);
// 					i++;
// 				}
// 				continue ;
// 			}
// 		}
// 		token[token_index++] = current;
// 		i++;
// 	}
// 	if (token_index != 0)
// 	{
// 		token[token_index] = '\0';
// 		result[result_index++] = strdup(token);
// 	}
// 	result[result_index] = NULL;
// 	if (in_single_quote || in_double_quote)
// 	{
// 		printf("Syntax error: unmatched quote\n");
// 		j = 0;
// 		while (j < result_index)
// 			free(result[j++]);
// 		free(result);
// 		return (NULL);
// 	}
// 	return (result);
// }

static void	init_split_state(t_split_state *state)
{
	state->result = (char **)malloc(128 * sizeof(char *));
	state->token = malloc(1024);
	state->in_single_quote = 0;
	state->in_double_quote = 0;
	state->token_index = 0;
	state->result_index = 0;
	state->i = 0;
}

static void	cleanup_split_state(t_split_state *state)
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

static void	add_token_if_needed(t_split_state *state)
{
	if (state->token_index != 0)
	{
		state->token[state->token_index] = '\0';
		state->result[state->result_index++] = strdup(state->token);
		state->token_index = 0;
	}
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
		state->token[state->token_index++] = current;
	}
	else if (!state->in_single_quote && !state->in_double_quote)
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
			if ((current == '>' || current == '<')
				&& str[state->i + 1] == current)
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
	else
		state->token[state->token_index++] = current;
}

char	**custom_split(char *str)
{
	t_split_state	state;

	init_split_state(&state);
	if (!state.result || !state.token)
		return (NULL);
	while (str[state.i])
	{
		handle_character(&state, str);
		state.i++;
	}
	add_token_if_needed(&state);
	state.result[state.result_index] = NULL;
	cleanup_split_state(&state);
	return (state.result);
}
