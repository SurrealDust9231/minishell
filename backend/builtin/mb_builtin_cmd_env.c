/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:14:24 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 20:56:07 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbb_cmd_env(char **av, t_minsh *minsh)
{
	if (!av)
	{
		minsh->status = 1;
		return (-1);
	}
	minsh->status = 0;
	ft_envlst_showall(minsh->elst);
	return (0);
}
