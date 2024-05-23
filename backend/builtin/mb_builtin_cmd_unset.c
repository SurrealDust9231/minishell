/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:14:24 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 20:56:33 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbb_cmd_unset(char **av, t_minsh *minsh)
{
	int	i;

	i = 1;
	while (av[i])
		ft_envlst_delone(&minsh->elst, av[i++]);
	minsh->status = 0;
	return (0);
}
