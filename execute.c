/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:05 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 21:16:09 by chang-pa         ###   ########.fr       */
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

void executePipe(t_astree *left, t_astree *right)
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

void executeRedirectOut(t_astree *node)
{
	char	**args;

	args = node->data;
    int original_stdout = dup(STDOUT_FILENO);
    int fd = open(args[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
	{
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    executeAST(node->l);
    dup2(original_stdout, STDOUT_FILENO);
    close(original_stdout);
}

void executeRedirectAppend(t_astree *node)
{
	char	**args;

	args = node->data;
    int original_stdout = dup(STDOUT_FILENO);
    int fd = open(args[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
	{
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    executeAST(node->l);
    dup2(original_stdout, STDOUT_FILENO);
    close(original_stdout);
}

void executeRedirectIn(t_astree *node)
{
	char	**args;

	args = node->data;
	int fd = open(args[0], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	executeAST(node->l);
}

void executeRedirectHeredoc(t_astree *node)
{
	int fds[2];
	char	**args;

	args = node->data;
	pipe(fds);

	if (fork() == 0)
	{
		close(fds[0]);
		write(fds[1], args[0], strlen(args[0]));
		close(fds[1]);
		exit(0);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		executeAST(node->l);
		wait(NULL);
	}
}

void handle_command(t_astree *node)
{
	char	**args;

	args = node->data;
	if (node && args)
		executeCommand(args);
}

void handle_pipe(t_astree *node)
{
	if (node && node->l && node->r)
		executePipe(node->l, node->r);
}
void handle_redirect_out(t_astree *node)
{
	if (node && node->data && node->l)
		executeRedirectOut(node);
}
void handle_redirect_append(t_astree *node)
{
	if (node && node->data && node->l)
		executeRedirectAppend(node);
}

void handle_redirect_in(t_astree *node)
{
	if (node && node->data && node->l)
		executeRedirectIn(node);
}

void handle_redirect_heredoc(t_astree *node)
{
	if (node && node->data && node->l)
		executeRedirectHeredoc(node);
}

t_node_handler_mapping TK_handlers[] = {
	{TK_COMMAND, handle_command},
	{TK_PIPE, handle_pipe},
	{TK_REDIRECT_OUT, handle_redirect_out},
	{TK_REDIRECT_APPEND, handle_redirect_append},
	{TK_REDIRECT_IN, handle_redirect_in},
	{TK_REDIRECT_HEREDOC, handle_redirect_heredoc},
	{0, NULL}
};

void executeAST(t_astree *node)
{
	int i = 0;

	if (node == NULL)
		return;
	while (TK_handlers[i].handler != NULL)
	{
		if (TK_handlers[i].type == node->type)
		{
			TK_handlers[i].handler(node);
			break ;
		}
		i++;
	}
}
