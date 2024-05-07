/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/06 23:32:27 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbes_cmd_return(char **path, int r)
{
	if (*path)
	{
		free(*path);
		*path = NULL;
	}
	return (r);
}

int	mbe_simple_cmd(t_astree *node)
{
	char	*path;
	char	**av;

	av = node->data;
	path = NULL;
	if (ft_strchr(av[0], '/'))
	{
		if (mbe_nbuiltin_cmd(node->data, path) != 0)
			return (-1);
	}
	else if (mbe_builtin_search(&path, av[0], MINISHELL_ROOT_DIR) != 0)
		return (ft_error_return("_mbes_cmd1", -1));
	else if (path)
	{
		if (mbe_builtin_cmd(node->data, path) != 0)
			return (_mbes_cmd_return(&path, -1));
	}
	else if (mbe_nbuiltin_search(&path, av[0]) != 0)
		return (ft_error_return("_mbes_cmd2", -1));
	else if (path)
	{
		if (mbe_nbuiltin_cmd(node->data, path) != 0)
			return (_mbes_cmd_return(&path, -1));
	}
	return (_mbes_cmd_return(&path, 0));
}
