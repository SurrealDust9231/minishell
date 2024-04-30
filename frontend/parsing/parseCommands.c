/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseCommands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:56:40 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/30 16:24:52 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

t_astree *create_redirection_node(char **tokens, int *index, t_astree *left, int type)
{
	char **args = malloc(2 * sizeof(char *));
	args[0] = tokens[*index];
	args[1] = NULL;
	t_astree *right;
	if (ft_ast_create(&right) != 0)
		return NULL;
	ft_ast_init(right, type, args);
	(*index)++;
	right->l = left;
	printf("Creating redirect node for %s\n", args[0]);
	return right;
}

t_astree *parseCommands(char **tokens, int *index)
{
	t_astree *left;
	t_astree *right;
	t_astree *pipe_node;

	int arg_count = 0;
	while (tokens[*index + arg_count] != NULL &&
		   ft_strcmp(tokens[*index + arg_count], "|") != 0 &&
		   ft_strcmp(tokens[*index + arg_count], ">") != 0 &&
		   ft_strcmp(tokens[*index + arg_count], ">>") != 0 &&
		   ft_strcmp(tokens[*index + arg_count], "<") != 0 &&
		   ft_strcmp(tokens[*index + arg_count], "<<") != 0)
	{
		arg_count++;
	}
	char **cmd_args = malloc((arg_count + 1) * sizeof(char *));
	int i = 0;
	while (i < arg_count)
	{
		cmd_args[i] = tokens[*index + i];
		i++;
	}
	cmd_args[arg_count] = NULL;
	if (ft_ast_create(&left) != 0)
		return NULL;
	ft_ast_init(left, TK_COMMAND, cmd_args);
	printf("Creating command node: %s\n", tokens[*index]);
	*index += arg_count;
	// Manejar operadores
	while (tokens[*index] != NULL)
	{
		if (ft_strcmp(tokens[*index], "|") == 0)
		{
			(*index)++;
			right = parseCommands(tokens, index);
			if (ft_ast_create(&pipe_node) != 0)
				return NULL;
			ft_ast_init(pipe_node, TK_PIPE, NULL);
			pipe_node->l = left;
			pipe_node->r = right;
			left = pipe_node;
			printf("Creating pipe node\n");
		}
		else if (ft_strcmp(tokens[*index], ">") == 0)
		{
			(*index)++;
			left = create_redirection_node(tokens, index, left, TK_REDIRECT_OUT);
		}
		else if (ft_strcmp(tokens[*index], ">>") == 0)
		{
			(*index)++;
			left = create_redirection_node(tokens, index, left, TK_REDIRECT_APPEND);
		}
		else if (ft_strcmp(tokens[*index], "<") == 0)
		{
			(*index)++;
			left = create_redirection_node(tokens, index, left, TK_REDIRECT_IN);
		}
		else if (ft_strcmp(tokens[*index], "<<") == 0)
		{
			(*index)++;
			left = create_redirection_node(tokens, index, left, TK_REDIRECT_HEREDOC);
		}
		else
		{
			printf("Breaking on token: %s\n", tokens[*index]);
			break;
		}
	}
	return left;
}
