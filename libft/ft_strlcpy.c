/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:06:36 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 21:10:31 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strlcpy_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = _ft_strlcpy_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i + 1 < dstsize && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
