/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:29:04 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/06 21:31:00 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftend.h"

int	ft_puterr_return(const char *msg, int r)
{
	while (*msg != '\0')
		write(STDERR_FILENO, msg++, 1);
	return (r);
}
