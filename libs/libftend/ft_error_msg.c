/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:29:04 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 20:47:56 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftend.h"

static void	_ft_error_cnf_putstr(const char *s, int fd)
{
	while (*s != 0)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_error_cnf(const char *arg)
{
	_ft_error_cnf_putstr("minishell: command not found: ", STDERR_FILENO);
	_ft_error_cnf_putstr(arg, STDERR_FILENO);
	_ft_error_cnf_putstr("\n", STDERR_FILENO);
}
