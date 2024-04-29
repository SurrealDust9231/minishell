/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:58:51 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 21:15:50 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (str[i] != (unsigned char)c)
	{
		if (i + 1 >= n)
			break ;
		i++;
	}
	if (n != 0 && str[i] == (unsigned char)c)
		return ((void *)(s + i));
	return (NULL);
}
