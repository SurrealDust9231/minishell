/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:14:24 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:54:41 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbb_cmd_unset_check(char *key)
{
	int	i;

	i = 0;
	if (ft_isalpha(key[i]) == 0 && key[i] != '_')
		return (-1);
	i++;
	while (key[i])
	{
		if (ft_isalnum(key[i]) == 0 && key[i] != '_')
			return (-1);
		i++;
	}
	return (0);
}

int	mbb_cmd_unset(char **av, t_minsh *minsh)
{
	int	i;

	minsh->status = 0;
	i = 1;
	while (av[i])
	{
		if (_mbb_cmd_unset_check(av[i]) != 0)
		{
			minsh->status = 1;
			ft_error_nvi(av[0], av[i]);
		}
		else
			ft_envlst_delone(&minsh->elst, av[i]);
		i++;
	}
	return (0);
}
