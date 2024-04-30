/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:30:21 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbe_redirect_out(t_astree *node)
{
	int	original_stdout;
	int	fd;

	original_stdout = dup(STDOUT_FILENO);
	fd = open(((char **)node->data)[0], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_error_return("mbe_redirect_out", -1));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	mbe_execute_node(node->l);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (0);
}

int	mbe_redirect_append(t_astree *node)
{
	int	original_stdout;
	int	fd;

	original_stdout = dup(STDOUT_FILENO);
	fd = open(((char **)node->data)[0], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (ft_error_return("mbe_redirect_append", -1));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	mbe_execute_node(node->l);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (0);
}

int	mbe_redirect_in(t_astree *node)
{
	int	original_stdin;
	int	fd;

	original_stdin = dup(STDIN_FILENO);
	fd = open(((char **)node->data)[0], O_RDONLY);
	if (fd == -1)
		return (ft_error_return("mbe_redirect_in", -1));
	dup2(fd, STDIN_FILENO);
	close(fd);
	mbe_execute_node(node->l);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	return (0);
}

int	mbe_redirect_heredoc(t_astree *node)
{
	int		fds[2];
	char	**args;
	pid_t	pid;

	args = node->data;
	if (pipe(fds) == -1)
		return (ft_error_return("mbe_redirect_heredoc1", -1));
	pid = fork();
	if (pid == -1)
		return (ft_error_return("mbe_redirect_heredoc2", -1));
	else if (pid == 0)
	{
		close(fds[0]);
		write(fds[1], args[0], strlen(args[0]));
		close(fds[1]);
		exit(0);
	}
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	wait(NULL);
	close(fds[0]);
	mbe_execute_node(node->l);
	return (0);
}
