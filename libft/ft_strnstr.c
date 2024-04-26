/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:29:18 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 16:22:53 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strnstr_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int	_ft_strnstr_hncmp(const char *haystack, const char *needle, size_t len)
{
	while (*haystack == *needle)
	{
		if (len == 0 || *haystack == 0)
			break ;
		len--;
		haystack++;
		needle++;
	}
	if (*needle != 0)
		return (-1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = _ft_strnstr_strlen(needle);
	if (needle == NULL || i == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != 0 && i < len)
	{
		if (_ft_strnstr_hncmp(haystack + i, needle, len - i) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
