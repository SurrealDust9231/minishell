/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:36:09 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 10:43:32 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = n % 10 + '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n / 10 != 0)
			ft_putnbr_fd(-(n / 10), fd);
		c = -(n % 10) + '0';
	}
	else if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &c, 1);
}
