/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:14:24 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:45:28 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbb_cmd_export_split(char *env)
{
	int	len;

	len = 0;
	while (env[len])
	{
		if (env[len] == '=')
		{
			if (len == 0 || env[len + 1] == '\0')
				return (-1);
			env[len] = '\0';
			return (len);
		}
		len++;
	}
	return (-1);
}

static int	_mbb_cmd_export_check(char *key)
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

int	mbb_cmd_export(char **av, t_minsh *minsh)
{
	int	i;
	int	len;

	i = 0;
	minsh->status = 0;
	while (av[i])
	{
		len = _mbb_cmd_export_split(av[i]);
		if (_mbb_cmd_export_check(av[i]) != 0)
		{
			minsh->status = 1;
			ft_error_nvi(av[0], av[i]);
		}
		else if (len != -1 \
			&& ft_envlst_set(&minsh->elst, av[i], av[i] + len + 1) != 0)
			return (-1);
		i++;
	}
	return (0);
}
