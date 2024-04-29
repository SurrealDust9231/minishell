/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:05 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 19:13:18 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void executeCommand(char **args)
{
	if (ft_strcmp(args[0], "pwd") == 0)
	{
		execute_pwd();
	}
	else if (ft_strcmp(args[0], "echo") == 0)
	{
		execute_echo(args);
	}
	else if (ft_strcmp(args[0], "cd") == 0)
	{
		execute_cd(args);
	}
	// else
	// {
	//     // more commands
	// }
}

void executePipe(t_node *left, t_node *right)
{
	int fds[2];

	pipe(fds);
	if (fork() == 0)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		executeAST(left);
		exit(0);
	}
	else
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		executeAST(right);
		wait(NULL);
	}
}

void executeRedirectOut(t_node *node)
{
    int original_stdout = dup(STDOUT_FILENO);
    int fd = open(node->args[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
	{
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    executeAST(node->left);
    dup2(original_stdout, STDOUT_FILENO);
    close(original_stdout);
}

void executeRedirectAppend(t_node *node)
{
    int original_stdout = dup(STDOUT_FILENO);
    int fd = open(node->args[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
	{
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    executeAST(node->left);
    dup2(original_stdout, STDOUT_FILENO);
    close(original_stdout);
}

void executeRedirectIn(t_node *node)
{
	int fd = open(node->args[0], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	executeAST(node->left);
}

void executeRedirectHeredoc(t_node *node)
{
	int fds[2];
	pipe(fds);

	if (fork() == 0)
	{
		close(fds[0]);
		write(fds[1], node->args[0], strlen(node->args[0]));
		close(fds[1]);
		exit(0);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		executeAST(node->left);
		wait(NULL);
	}
}

void handle_command(t_node *node)
{
	if (node && node->args)
		executeCommand(node->args);	
}

void handle_pipe(t_node *node)
{
	if (node && node->left && node->right)
		executePipe(node->left, node->right);
}
void handle_redirect_out(t_node *node)
{
	if (node && node->args && node->left)
		executeRedirectOut(node);
}
void handle_redirect_append(t_node *node)
{
	if (node && node->args && node->left)
		executeRedirectAppend(node);
}

void handle_redirect_in(t_node *node)
{
	if (node && node->args && node->left)
		executeRedirectIn(node);
}

void handle_redirect_heredoc(t_node *node)
{
	if (node && node->args && node->left)
		executeRedirectHeredoc(node);
}

t_node_handler_mapping node_handlers[] = {
	{NODE_COMMAND, handle_command},
	{NODE_PIPE, handle_pipe},
	{NODE_REDIRECT_OUT, handle_redirect_out},
	{NODE_REDIRECT_APPEND, handle_redirect_append},
	{NODE_REDIRECT_IN, handle_redirect_in},
	{NODE_REDIRECT_HEREDOC, handle_redirect_heredoc},
	{0, NULL}
};

void executeAST(t_node *node)
{
	int i = 0;

	if (node == NULL)
		return;
	while (node_handlers[i].handler != NULL) 
	{
		if (node_handlers[i].type == node->type)
		{
			node_handlers[i].handler(node);
			break ;
		}
		i++;
	}
}