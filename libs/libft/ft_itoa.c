/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:48:50 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/12 22:40:49 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_itoa_get_len(int n)
{
	size_t	len;
	int		tmp;

	len = 1;
	if (n < 0)
		len++;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*rt;
	size_t			len;
	unsigned int	un;

	len = _ft_itoa_get_len(n);
	rt = (char *) malloc(sizeof(char) * (len + 1));
	if (rt == NULL)
		return (NULL);
	rt[len] = 0;
	if (n < 0)
	{
		rt[0] = '-';
		un = -n;
	}
	else
		un = n;
	while (un / 10 != 0)
	{
		rt[--len] = un % 10 + '0';
		un = un / 10;
	}
	rt[--len] = un % 10 + '0';
	return (rt);
}
