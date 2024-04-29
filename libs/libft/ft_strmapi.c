/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:22:02 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 10:27:26 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strmapi_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rt;
	size_t	len;
	size_t	i;

	len = _ft_strmapi_strlen(s);
	rt = (char *) malloc(sizeof(char) * (len + 1));
	if (rt == NULL)
		return (NULL);
	rt[len] = 0;
	i = 0;
	while (i < len)
	{
		rt[i] = f(i, s[i]);
		i++;
	}
	return (rt);
}
