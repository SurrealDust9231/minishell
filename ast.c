/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:56:40 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 20:17:44 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *createNode(t_node_type type, char **args)
{
	t_node *node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->args = args;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node *parseCommands(char **tokens, int *index)
{
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
    t_node *left = createNode(NODE_COMMAND, cmd_args);
    printf("Creating command node: %s\n", tokens[*index]);
    *index += arg_count;
    while (tokens[*index] != NULL)
    {
        if (ft_strcmp(tokens[*index], "|") == 0)
        {
            (*index)++;
            t_node *right = parseCommands(tokens, index);
            t_node *pipe_node = createNode(NODE_PIPE, NULL);
            pipe_node->left = left;
            pipe_node->right = right;
            left = pipe_node;
            printf("Creating pipe node\n");
        }
        else if (ft_strcmp(tokens[*index], ">") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
            t_node *right = createNode(NODE_REDIRECT_OUT, args);
            (*index)++;
            right->left = left;
            left = right;
            printf("Creating redirect > node\n");
        }
        else if (ft_strcmp(tokens[*index], ">>") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
            t_node *right = createNode(NODE_REDIRECT_APPEND, args);
            (*index)++;
            right->left = left;
            left = right;
            printf("Creating redirect >> node\n");
        }
        else if (ft_strcmp(tokens[*index], "<") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
            t_node *right = createNode(NODE_REDIRECT_IN, args);
            (*index)++;
            right->left = left;
            left = right;
            printf("Creating redirect < node\n");
        }
        else if (ft_strcmp(tokens[*index], "<<") == 0)
        {
            (*index)++;
            char **args = malloc(2 * sizeof(char *));
            args[0] = tokens[*index];
            args[1] = NULL;
            t_node *right = createNode(NODE_REDIRECT_HEREDOC, args);
            (*index)++;
            right->left = left;
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
