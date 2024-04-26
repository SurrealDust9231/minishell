/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:06:22 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 21:10:50 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strlcat_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = _ft_strlcat_strlen(src);
	if (dstsize == 0)
		return (len_src);
	i = 0;
	while (dst[i] != 0 && i < dstsize)
		i++;
	if (dst[i] != 0)
		return (len_src + i);
	len_dst = i;
	while (src[i - len_dst] != 0 && i + 1 < dstsize)
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	dst[i] = 0;
	return (len_src + len_dst);
}
