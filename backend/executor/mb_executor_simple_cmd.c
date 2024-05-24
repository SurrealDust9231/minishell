/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 20:33:41 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbes_cmd_return(char **path, t_minsh *minsh, int exr, char *av)
{
	int	r;

	r = 0;
	if (exr == 127)
	{
		minsh->status = exr;
		ft_error_cnf(av);
	}
	else if (exr == 1)
	{
		minsh->status = exr;
		r = -1;
	}
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

	if (!av || !av[0])
		return (0);
	path = NULL;
	if (ft_strchr(av[0], '/'))
		return (mbn_cmd(node->data, path, minsh));
	else if (mbb_search(&path, av[0], MINISHELL_ROOT_DIR) != 0)
		return (ft_error_return("_mbes_cmd1", -1));
	else if (path)
	{
		if (mbb_cmd(node->data, path, minsh) != 0)
			return (_mbes_cmd_return(&path, minsh, 1, av[0]));
	}
	else if (mbn_search(&path, av[0], minsh) != 0)
		return (ft_error_return("_mbes_cmd2", -1));
	else if (path)
	{
		if (mbn_cmd(node->data, path, minsh) != 0)
			return (_mbes_cmd_return(&path, minsh, 1, av[0]));
	}
	else
		return (_mbes_cmd_return(&path, minsh, 127, av[0]));
	return (_mbes_cmd_return(&path, minsh, 0, av[0]));
}
