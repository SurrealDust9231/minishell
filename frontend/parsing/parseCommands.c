/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseCommands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:56:40 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 21:08:12 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

t_astree *parseCommands(char **tokens, int *index)
{
	t_astree *left;
	t_astree *right;
	t_astree *pipe_node;

    int arg_count = 0;
    while (tokens[*index + arg_count] != NULL && ft_strcmp(tokens[*index + arg_count], "|") != 0 &&
           ft_strcmp(tokens[*index + arg_count], ">") != 0 && ft_strcmp(tokens[*index + arg_count], ">>") != 0 &&
           ft_strcmp(tokens[*index + arg_count], "<") != 0 && ft_strcmp(tokens[*index + arg_count], "<<") != 0)
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
		return (NULL);
	ft_ast_init(left, TK_COMMAND, cmd_args);
    printf("Creating command node: %s\n", tokens[*index]);
    *index += arg_count;
    while (tokens[*index] != NULL)
    {
        if (ft_strcmp(tokens[*index], "|") == 0)
        {
            (*index)++;
            right = parseCommands(tokens, index);
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
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
			if (ft_ast_create(&right) != 0)
				return (NULL);
			ft_ast_init(right, TK_REDIRECT_OUT, args);
            (*index)++;
            right->l = left;
            left = right;
            printf("Creating redirect > node\n");
        }
        else if (ft_strcmp(tokens[*index], ">>") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
			if (ft_ast_create(&right) != 0)
				return (NULL);
			ft_ast_init(right, TK_REDIRECT_APPEND, args);
            (*index)++;
            right->l = left;
            left = right;
            printf("Creating redirect >> node\n");
        }
        else if (ft_strcmp(tokens[*index], "<") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
			if (ft_ast_create(&right) != 0)
				return (NULL);
			ft_ast_init(right, TK_REDIRECT_IN, args);
            (*index)++;
            right->l = left;
            left = right;
            printf("Creating redirect < node\n");
        }
        else if (ft_strcmp(tokens[*index], "<<") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
			if (ft_ast_create(&right) != 0)
				return (NULL);
			ft_ast_init(right, TK_REDIRECT_HEREDOC, args);
            (*index)++;
            right->l = left;
            left = right;
            printf("Creating redirect << node\n");
        }
        else
        {
            printf("Breaking on token: %s\n", tokens[*index]);
            break;
        }
    }
    return (left);
}
