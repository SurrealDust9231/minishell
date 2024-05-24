/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 14:30:29 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbe_pipe_left(t_astree *left, \
	pid_t pid, int fds[2], t_minsh *minsh)
{
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		mbe_execute_node(left, minsh);
		exit(minsh->status);
	}
	else if (pid < 0)
		return (ft_error_return("_mbe_pipe_left: ", -1));
	return (0);
}

static int	_mbe_pipe_right(t_astree *right, \
	pid_t pid, int fds[2], t_minsh *minsh)
{
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		mbe_execute_node(right, minsh);
		exit(minsh->status);
	}
	else if (pid < 0)
		return (ft_error_return("_mbe_pipe_right: ", -1));
	return (0);
}

int	mbe_pipe(t_astree *node, t_minsh *minsh)
{
	int		fds[2];
	pid_t	pid[2];
	int		status;

	if (pipe(fds) == -1)
		return (ft_error_return("mbe_pipe1: ", -1));
	pid[0] = fork();
	if (pid[0] < 1 && _mbe_pipe_left(node->l, pid[0], fds, minsh) != 0)
		return (ft_error_return("mbe_pipe2: ", -1));
	else if (pid[0] > 0)
	{
		pid[1] = fork();
		if (pid[1] < 1 && _mbe_pipe_right(node->r, pid[1], fds, minsh) != 0)
			return (ft_error_return("mbe_pipe3: ", -1));
		else if (pid[1] > 0)
		{
			close(fds[0]);
			close(fds[1]);
			waitpid(pid[0], &status, 0);
			waitpid(pid[1], &status, 0);
			minsh->status = status / 256;
		}
	}
	return (0);
}
