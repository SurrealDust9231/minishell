/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:49:19 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 16:48:52 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_split_words(const char *s, char c)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = 0;
	while (*s != 0)
	{
		if (*s != c)
			len++;
		else if (len > 0)
		{
			count++;
			len = 0;
		}
		s++;
	}
	if (len > 0)
		count++;
	return (count);
}

char	*_ft_split_get_word(const char *s, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}

int	_ft_split_flush(char **rt, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(rt[i++]);
	free(rt);
	return (-1);
}

int	_ft_split_get_words(char **dst, char const *s, char c, size_t words)
{
	size_t	len;

	len = 0;
	while (*s != 0)
	{
		if (*s != c)
			len++;
		else if (len > 0)
		{
			dst[words] = _ft_split_get_word(s - len, len);
			if (dst[words] == NULL)
				return (_ft_split_flush(dst, words));
			len = 0;
			words++;
		}
		s++;
	}
	if (len > 0)
	{
		dst[words] = _ft_split_get_word(s - len, len);
		if (dst[words] == NULL)
			return (_ft_split_flush(dst, words));
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**rt;
	size_t	words;

	words = _ft_split_words(s, c);
	rt = (char **) malloc(sizeof(char *) * (words + 1));
	if (rt == NULL)
		return (NULL);
	rt[words] = NULL;
	if (_ft_split_get_words(rt, s, c, 0) != 0)
		return (NULL);
	return (rt);
}
