/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:43:37 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:11:05 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftend.h"

static void	_ft_error_return_putstr(const char *s, int fd)
{
	while (*s != 0)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_error_return(const char *arg, int rt)
{
	perror(arg);
	return (rt);
}

int	ft_error_tma_return(const char *arg, int rt)
{
	_ft_error_return_putstr("minishell: ", STDERR_FILENO);
	_ft_error_return_putstr(arg, STDERR_FILENO);
	_ft_error_return_putstr(": too many arguments", STDERR_FILENO);
	_ft_error_return_putstr("\n", STDERR_FILENO);
	return (rt);
}

int	ft_error_nar_return(const char *arg, const char *msg, int rt)
{
	_ft_error_return_putstr("minishell: ", STDERR_FILENO);
	_ft_error_return_putstr(arg, STDERR_FILENO);
	_ft_error_return_putstr(": ", STDERR_FILENO);
	_ft_error_return_putstr(msg, STDERR_FILENO);
	_ft_error_return_putstr(": numeric argument required", STDERR_FILENO);
	_ft_error_return_putstr("\n", STDERR_FILENO);
	return (rt);
}
