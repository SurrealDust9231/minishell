/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:40:04 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 21:12:26 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strnlen(const char *s, size_t max_len)
{
	size_t	len;

	len = 0;
	while (len < max_len && s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = _ft_strnlen(s1, n);
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	i = 0;
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}
