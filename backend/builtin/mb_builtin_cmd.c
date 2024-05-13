/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:37:33 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/13 18:13:59 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbe_builtin_cmd_execv(char **av, char *path)
{
	if (execve(path, av, NULL) != 0)
		return (ft_error_return("_mbeb_execv1", -1));
	return (0);
}

int	mbb_cmd(char **av, char *path)
{
	pid_t	child_pid;
	int		status;

	if (!av)
		return (0);
	child_pid = fork();
	if (child_pid == 0)
	{
		_mbe_builtin_cmd_execv(av, path);
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		return (ft_error_return("mbeb_cmd1", -1));
	status = 0;
	waitpid(child_pid, &status, 0);
	return (0);
}
