/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 17:51:54 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_backend.h"

static int	_mbes_execv(char **argv)
{
	char	*path;

	if (ft_strchr(argv[0], '/'))
		execve(argv[0], argv, NULL);
	else
	{
		path = mbe_search_path(argv[0]);
		if (!path)
			return (0);
		execve(path, argv, NULL);
		free(path);
	}
	return (0);
}

int	mbe_simple_cmd(t_astree *node)
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
