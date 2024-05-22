/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:01:01 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/21 13:20:54 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

t_astree	*create_red_node(char **tokens,
	int *index, t_astree *left, int type)
{
	t_astree	*right;
	char		**args;

	args = malloc(2 * sizeof(char *));
	args[0] = tokens[*index];
	args[1] = NULL;
	if (ft_ast_create(&right) != 0)
		return (NULL);
	ft_ast_init(right, type, args);
	(*index)++;
	right->l = left;
	// printf("Creating redirect node for %s\n", args[0]);
	return (right);
}

t_astree	*handle_redirect_tokens(char **tokens, int *index, t_astree *left)
{
	if (ft_strcmp(tokens[*index], ">") == 0)
	{
		(*index)++;
		left = create_red_node(tokens, index, left, TK_REDIRECT_OUT);
	}
	else if (ft_strcmp(tokens[*index], ">>") == 0)
	{
		(*index)++;
		left = create_red_node(tokens, index, left, TK_REDIRECT_APPEND);
	}
	else if (ft_strcmp(tokens[*index], "<") == 0)
	{
		(*index)++;
		left = create_red_node(tokens, index, left, TK_REDIRECT_IN);
	}
	else if (ft_strcmp(tokens[*index], "<<") == 0)
	{
		(*index)++;
		left = create_red_node(tokens, index, left, TK_REDIRECT_HEREDOC);
	}
	return (left);
}
