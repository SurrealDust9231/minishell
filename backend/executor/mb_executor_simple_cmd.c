/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/13 18:14:35 by chang-pa         ###   ########.fr       */
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

static int	_mbes_cmd_av_count(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

static int	_mbes_cmd_cd(char **av)
{
	if (!av)
		return (0);
	if (_mbes_cmd_av_count(av) != 2)
		return (ft_puterr_return(\
				"cd: wrong number of arguments\n", -1));
	if (chdir(av[1]) != 0)
		return (ft_error_return(av[0], -1));
	return (0);
}

int	mbe_simple_cmd(t_astree *node)
{
	char	*path;
	char	**av;

	av = node->data;
	path = NULL;
	if (ft_strcmp(av[0], "cd") == 0)
		return(_mbes_cmd_cd(node->data));
	else if (ft_strchr(av[0], '/'))
		return (mbn_cmd(node->data, path));
	else if (mbb_search(&path, av[0], MINISHELL_ROOT_DIR) != 0)
		return (ft_error_return("_mbes_cmd1", -1));
	else if (path)
	{
		if (mbb_cmd(node->data, path) != 0)
			return (_mbes_cmd_return(&path, -1));
	}
	else if (mbn_search(&path, av[0]) != 0)
		return (ft_error_return("_mbes_cmd2", -1));
	else if (path)
	{
		if (mbn_cmd(node->data, path) != 0)
			return (_mbes_cmd_return(&path, -1));
	}
	return (_mbes_cmd_return(&path, 0));
}
