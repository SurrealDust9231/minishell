/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_cmd_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:24:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:18:46 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mbb_cmd_exit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
			return (-1);
	}
	return (0);
}

static int	_mbb_cmd_exit_parse(char *str)
{
	int	n;

	n = ft_atoi(str) % 256;
	return (n);
}

static int	_mbb_cmd_exit_count(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

int	mbb_cmd_exit(char **av, t_minsh *minsh)
{
	int	n;

	if (!av)
		return (-1);
	n = 0;
	if (av[1] != NULL)
	{
		if (_mbb_cmd_exit_check(av[1]) != 0)
			exit(ft_error_nar_return(av[0], av[1], 255));
		n = _mbb_cmd_exit_parse(av[1]);
		if (n < 0)
			exit(ft_error_nar_return(av[0], av[1], 255));
	}
	if (_mbb_cmd_exit_count(av) > 2)
	{
		minsh->status = 1;
		ft_error_tma_return(av[0], 1);
		return (0);
	}
	exit(n);
	return (0);
}
