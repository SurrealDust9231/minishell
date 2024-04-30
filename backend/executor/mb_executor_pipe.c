/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 13:16:57 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int mbe_pipe(t_astree *node)
{
	int fds[2];

	pipe(fds);
	if (fork() == 0)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		mbe_execute_node(node->l);
		exit(0);
	}
	else
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		wait(NULL);
		mbe_execute_node(node->r);
	}
	return (0);
}
