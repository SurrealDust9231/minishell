/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:29:47 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/12 22:48:00 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strjoin_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*tmp;
	size_t	len;

	len = 0;
	if (s1 != NULL)
		len += _ft_strjoin_strlen(s1);
	if (s2 != NULL)
		len += _ft_strjoin_strlen(s2);
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = 0;
	tmp = dst;
	if (s1 != NULL)
	{
		while (*s1 != 0)
			*tmp++ = *s1++;
	}
	if (s2 != NULL)
	{
		while (*s2 != 0)
			*tmp++ = *s2++;
	}
	return (dst);
}
