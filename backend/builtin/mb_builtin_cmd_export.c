/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:14:24 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 19:58:19 by chang-pa         ###   ########.fr       */
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

int	mbb_cmd_export(char **av, t_minsh *minsh)
{
	int	i;
	int	len;

	i = 0;
	while (av[i])
	{
		len = _mbb_cmd_export_split(av[i]);
		if (len != -1 \
			&& ft_envlst_set(&minsh->elst, av[i], av[i] + len + 1) != 0)
			return (ft_error_return(av[0], -1));
		i++;
	}
	return (0);
}
