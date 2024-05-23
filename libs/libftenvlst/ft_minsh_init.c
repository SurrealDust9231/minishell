/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minsh_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:16:40 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 21:21:29 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

int	ft_minsh_init(t_minsh **minsh, char **envs)
{
	*minsh = (t_minsh *) malloc(sizeof(t_minsh));
	if (*minsh == NULL)
		return (-1);
	(*minsh)->elst = NULL;
	(*minsh)->status = 0;
	if (ft_envlst_init(&(*minsh)->elst, envs) != 0)
	{
		ft_minsh_destroy(*minsh);
		return (-1);
	}
	return (0);
}
