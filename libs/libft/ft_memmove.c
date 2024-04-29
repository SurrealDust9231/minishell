/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:58:45 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 15:20:52 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s_dst;
	const unsigned char	*s_src;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	s_dst = dst;
	s_src = src;
	if (s_dst < s_src)
	{
		i = 0;
		while (i < len)
		{
			s_dst[i] = s_src[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			s_dst[len] = s_src[len];
	}
	return (dst);
}
