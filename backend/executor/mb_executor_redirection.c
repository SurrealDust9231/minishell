/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 13:23:32 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbe_redirect_out(t_astree *node)
{
	int	original_stdout;
	int	fd;

	original_stdout = dup(STDOUT_FILENO);
	fd = open(((char **)node->data)[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (-1);
	}
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
	fd = open(((char **)node->data)[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	mbe_execute_node(node->l);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (0);
}

int	mbe_redirect_in(t_astree *node)
{
	int	fd;

	fd = open(((char **)node->data)[0], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	mbe_execute_node(node->l);
	return (0);
}

int	mbe_redirect_heredoc(t_astree *node)
{
	int		fds[2];
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
		wait(NULL);
		close(fds[0]);
		mbe_execute_node(node->l);
	}
	return (0);
}
