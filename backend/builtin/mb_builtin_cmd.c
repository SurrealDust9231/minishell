/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:37:33 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 21:25:28 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbe_builtin_cmd_execv(char **av, char *path, t_minsh *minsh)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(path, av, NULL);
		ft_error_return("_mbeb_execv1", -1);
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		return (ft_error_return("mbeb_cmd1", -1));
	waitpid(child_pid, &minsh->status, 0);
	minsh->status = minsh->status / 256;
	return (0);
}

int	mbb_cmd(char **av, char *path, t_minsh *minsh)
{
	if (!av)
		return (0);
	if (ft_strcmp(path, "cd") == 0)
		return (mbb_cmd_cd(av, minsh));
	else if (ft_strcmp(path, "exit") == 0)
		return (mbb_cmd_exit(av, minsh));
	else if (ft_strcmp(path, "export") == 0)
		return (mbb_cmd_export(av, minsh));
	else if (ft_strcmp(path, "unset") == 0)
		return (mbb_cmd_unset(av, minsh));
	else if (ft_strcmp(path, "env") == 0)
		return (mbb_cmd_env(av, minsh));
	else if (ft_strcmp(path, "echo") == 0)
		return (mbb_cmd_echo(av, minsh));
	else
		return (_mbe_builtin_cmd_execv(av, path, minsh));
}
