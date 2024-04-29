/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_external_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 18:41:36 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_backend.h"

static int	_mbes_execv(char **argv)
{
	char	*path;
	int		r;

	r = 0;
	if (ft_strchr(argv[0], '/'))
	{
		if (execve(argv[0], argv, NULL) != 0)
			return (-1);
	}
	else
	{
		if (mbe_search_path(&path, argv[0]) != 0)
			return (-1);
		if (!path)
			return (0);
		if (execve(path, argv, NULL) != 0)
			return (-1);
		free(path);
	}
	return (r);
}

int	mbe_external_cmd(t_astree *node)
{
	pid_t	child_pid;
	int		status;

	if (!node)
		return (0);
	child_pid = fork();
	if (child_pid == 0)
	{
		_mbes_execv(node->data);
		ft_error_return("error: failed to execute command: ", -1);
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		return (ft_error_return("error: failed to fork command: ", -1));
	status = 0;
	waitpid(child_pid, &status, 0);
	return (0);
}
