/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:56:40 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/01 14:31:04 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

t_astree	*create_red_node(char **tokens, int *index, t_astree *left, int type)
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
	printf("Creating redirect node for %s\n", args[0]);
	return (right);
}

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
	i = -1;
	while (++i < arg_count)
		cmd_args[i] = tokens[*index + i];
	cmd_args[arg_count] = NULL;
	if (ft_ast_create(left) != 0)
		return (NULL);
	ft_ast_init(*left, TK_COMMAND, cmd_args);
	printf("Creating command node: %s\n", tokens[*index]);
	*index += arg_count;
	return (*left);
}

t_astree	*handle_special_tokens(char **tokens, int *index, t_astree *left)
{
	t_astree	*right;
	t_astree	*pipe_node;

	while (tokens[*index] != NULL)
	{
		if (ft_strcmp(tokens[*index], "|") == 0)
		{
			(*index)++;
			right = parse_commands(tokens, index);
			if (ft_ast_create(&pipe_node) != 0)
				return (NULL);
			ft_ast_init(pipe_node, TK_PIPE, NULL);
			pipe_node->l = left;
			pipe_node->r = right;
			left = pipe_node;
			printf("Creating pipe node\n");
		}
		else if (ft_strcmp(tokens[*index], ">") == 0)
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
