/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:56:40 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 18:51:27 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

t_astree	*parse_command_args(char **tokens, int *index, t_astree **left)
{
	char	**cmd_args;
	int		arg_count;
	int		i;

	arg_count = 0;
	while (tokens[*index + arg_count] != NULL
		&& ft_strcmp(tokens[*index + arg_count], "|") != 0
		&& ft_strcmp(tokens[*index + arg_count], ">") != 0
		&& ft_strcmp(tokens[*index + arg_count], ">>") != 0
		&& ft_strcmp(tokens[*index + arg_count], "<") != 0
		&& ft_strcmp(tokens[*index + arg_count], "<<") != 0)
		arg_count++;
	cmd_args = malloc((arg_count + 1) * sizeof(char *));
	if (cmd_args == NULL)
		return (NULL);
	i = -1;
	while (++i < arg_count)
		cmd_args[i] = ft_strdup(tokens[*index + i]);
	cmd_args[arg_count] = NULL;
	if (ft_ast_create(left) != 0)
		return (NULL);
	ft_ast_init(*left, TK_COMMAND, cmd_args);
	// printf("Creating command node: %s\n", tokens[*index]);
	*index += arg_count;
	return (*left);
}

t_astree	*handle_pipe(char **tokens, int *index, t_astree *left)
{
	t_astree	*right;
	t_astree	*pipe_node;

	right = parse_commands(tokens, index);
	if (ft_ast_create(&pipe_node) != 0)
		return (NULL);
	ft_ast_init(pipe_node, TK_PIPE, NULL);
	pipe_node->l = left;
	pipe_node->r = right;
	// printf("Creating pipe node\n");
	return (pipe_node);
}

t_astree	*handle_pipe_token(char **tokens, int *index, t_astree *left)
{
	(*index)++;
	return (handle_pipe(tokens, index, left));
}

t_astree	*handle_special_tokens(char **tokens, int *index, t_astree *left)
{
	while (tokens[*index] != NULL)
	{
		if (ft_strcmp(tokens[*index], "|") == 0)
		{
			left = handle_pipe_token(tokens, index, left);
		}
		else if (ft_strcmp(tokens[*index], ">") == 0
			|| ft_strcmp(tokens[*index], ">>") == 0
			|| ft_strcmp(tokens[*index], "<") == 0
			|| ft_strcmp(tokens[*index], "<<") == 0)
			left = handle_redirect_tokens(tokens, index, left);
		else
		{
			printf("Breaking on token: %s\n", tokens[*index]);
			break ;
		}
	}
	return (left);
}

t_astree	*parse_commands(char **tokens, int *index)
{
	t_astree	*left;

	left = parse_command_args(tokens, index, &left);
	if (left == NULL)
		return (NULL);
	left = handle_special_tokens(tokens, index, left);
	return (left);
}
