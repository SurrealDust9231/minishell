/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_cd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:47:26 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 14:28:27 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbbcc_av_count(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

int	mbb_cmd_cd(char **av, t_minsh *minsh)
{
	char	cwd[1024];

	if (!av || !minsh)
		return (0);
	if (_mbbcc_av_count(av) != 2)
	{
		minsh->status = 1;
		return (ft_error_tma_return(av[0], -1));
	}
	if (chdir(av[1]) != 0)
	{
		minsh->status = 1;
		return (ft_error_return(av[0], -1));
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL \
		|| ft_envlst_set(&minsh->elst, "PWD", cwd) != 0)
		return (ft_error_return(av[0], -1));
	minsh->status = 0;
	return (0);
}
