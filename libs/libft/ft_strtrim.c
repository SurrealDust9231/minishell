/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:49:01 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 21:30:07 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_is_set(char c, char const *set)
{
	while (*set != 0 && *set != c)
		set++;
	if (*set == 0)
		return (0);
	return (1);
}

size_t	_ft_strtrim_get_len(char const *s1, char const *set)
{
	size_t		len;

	len = 0;
	while (s1[len] != 0)
		len++;
	while (len >= 0)
	{
		if (_is_set(s1[len], set) == 0 && s1[len] != 0)
		{
			len++;
			break ;
		}
		else if (len == 0)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dst;
	size_t		len;
	size_t		i;

	i = 0;
	while (*s1 != 0 && _is_set(*s1, set) != 0)
		s1++;
	len = _ft_strtrim_get_len(s1, set);
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = 0;
	i = 0;
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}
