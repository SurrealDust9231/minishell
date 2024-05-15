/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_cd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:47:26 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/15 10:37:02 by chang-pa         ###   ########.fr       */
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

int	mbb_cmd_cd(char **av)
{
	if (!av)
		return (0);
	if (_mbbcc_av_count(av) != 2)
		return (ft_puterr_return(\
				"cd: wrong number of arguments\n", -1));
	if (chdir(av[1]) != 0)
		return (ft_error_return(av[0], -1));
	return (0);
}
