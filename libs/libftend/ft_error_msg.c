/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:29:04 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 12:58:09 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftend.h"

static void	_ft_error_msg_putstr(const char *s, int fd)
{
	while (*s != 0)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_error_cnf(const char *arg)
{
	_ft_error_msg_putstr("minishell: ", STDERR_FILENO);
	_ft_error_msg_putstr(arg, STDERR_FILENO);
	_ft_error_msg_putstr(": command not found", STDERR_FILENO);
	_ft_error_msg_putstr("\n", STDERR_FILENO);
}

void	ft_error_nvi(const char *arg, const char *msg)
{
	_ft_error_msg_putstr("minishell: ", STDERR_FILENO);
	_ft_error_msg_putstr(arg, STDERR_FILENO);
	_ft_error_msg_putstr(": ", STDERR_FILENO);
	_ft_error_msg_putstr(msg, STDERR_FILENO);
	_ft_error_msg_putstr(": not a valid identifier", STDERR_FILENO);
	_ft_error_msg_putstr("\n", STDERR_FILENO);
}

void	ft_error_msg(const char *msg)
{
	_ft_error_msg_putstr(msg, STDERR_FILENO);
}
