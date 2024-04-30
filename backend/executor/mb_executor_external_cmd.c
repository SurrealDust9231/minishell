/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_external_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:44:34 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbes_execv(char **argv)
{
	char	*path;

	if (ft_strchr(argv[0], '/'))
	{
		if (execve(argv[0], argv, NULL) != 0)
			return (ft_error_return("_mbes_execv1", -1));
	}
	else
	{
		if (mbe_search_path(&path, argv[0]) != 0)
			return (ft_error_return("_mbes_execv2", -1));
		if (!path)
			return (0);
		if (execve(path, argv, NULL) != 0)
			return (ft_error_return("_mbes_execv3", -1));
		free(path);
	}
	return (0);
}

int	mbe_external_cmd(char **argv)
{
	pid_t	child_pid;
	int		status;

	if (!argv)
		return (0);
	child_pid = fork();
	if (child_pid == 0)
	{
		_mbes_execv(argv);
		ft_error_return("mbe_external_cmd1", -1);
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		return (ft_error_return("mbe_external_cmd2", -1));
	status = 0;
	waitpid(child_pid, &status, 0);
	return (0);
}