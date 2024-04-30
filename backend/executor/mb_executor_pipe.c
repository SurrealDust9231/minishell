/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 16:27:37 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int mbe_pipe(t_astree *node)
{
	int fds[2];
	pid_t pid1, pid2;
	int status;

	if (pipe(fds) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid1 == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		mbe_execute_node(node->l);
		exit(EXIT_SUCCESS);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("fork");
			return (-1);
		}
		if (pid2 == 0)
		{
			close(fds[1]);
			dup2(fds[0], STDIN_FILENO);
			close(fds[0]);
			mbe_execute_node(node->r);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(fds[0]);
			close(fds[1]);
			waitpid(pid1, &status, 0);
			waitpid(pid2, &status, 0);
		}
	}
	return (0);
}
