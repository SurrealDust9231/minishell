/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:14:24 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 19:45:57 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbb_cmd_env(char **av, t_minsh *minsh)
{
	if (!av)
		return (-1);
	ft_envlst_showall(minsh->elst);
	return (0);
}
