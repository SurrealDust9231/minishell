/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 20:37:27 by chang-pa         ###   ########.fr       */
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

int	mbe_simple_cmd(t_astree *node, char **av, t_minsh *minsh)
{
	char	*path;

	if (!av)
		return (0);
	path = NULL;
	if (ft_strchr(av[0], '/'))
		return (mbn_cmd(node->data, path));
	else if (mbb_search(&path, av[0], MINISHELL_ROOT_DIR) != 0)
		return (ft_error_return("_mbes_cmd1", -1));
	else if (path)
	{
		if (mbb_cmd(node->data, path, minsh) != 0)
			return (_mbes_cmd_return(&path, -1));
	}
	else if (mbn_search(&path, av[0], minsh) != 0)
		return (ft_error_return("_mbes_cmd2", -1));
	else if (path)
	{
		if (mbn_cmd(node->data, path) != 0)
			return (_mbes_cmd_return(&path, -1));
	}
	else
		ft_error_cnf(av[0]);
	return (_mbes_cmd_return(&path, 0));
}
