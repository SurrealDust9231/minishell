/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtins_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:50:14 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:58:11 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	_mbb_cd_count_args(char **array)
{
	int	count;

	count = 0;
	while (array && *array++)
		count++;
	return (count);
}

int	mbb_cd(char **args)
{
	if (_mbb_cd_count_args(args) != 2)
	{
		printf("cd: wrong number of arguments\n");
		return (-1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("cd");
	}
	return (0);
}
