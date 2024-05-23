/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:54:42 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 19:44:13 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

static int	_ft_envlst_init_putenv(t_envlst **elst, char *env)
{
	int			i;
	t_envlst	*node;

	i = 0;
	while (env[i])
	{
		if (env[i] == '=')
		{
			env[i] = '\0';
			break ;
		}
		i++;
	}
	node = ft_envlst_create(env, env + i + 1);
	if (node == NULL)
		return (-1);
	ft_envlst_push(elst, node);
	return (0);
}

int	ft_envlst_init(t_envlst **elst, char **envs)
{
	while (*envs)
	{
		if (_ft_envlst_init_putenv(elst, *envs) != 0)
		{
			ft_envlst_destroy(elst);
			return (-1);
		}
		envs++;
	}
	return (0);
}
