/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_nbuiltin_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:38:08 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/06 23:31:36 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbe_nbuiltin_cmd_execv(char **av, char *path)
{
	if (path == NULL)
	{
		if (execve(av[0], av, NULL) != 0)
			return (ft_error_return("_mben_execv1", -1));
	}
	else
	{
		if (execve(path, av, NULL) != 0)
			return (ft_error_return("_mben_execv2", -1));
	}
	return (0);
}

int	mbe_nbuiltin_cmd(char **av, char *path)
{
	pid_t	child_pid;
	int		status;

	if (!av)
		return (0);
	child_pid = fork();
	if (child_pid == 0)
	{
		_mbe_nbuiltin_cmd_execv(av, path);
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		return (ft_error_return("mben_cmd1", -1));
	status = 0;
	waitpid(child_pid, &status, 0);
	return (0);
}
