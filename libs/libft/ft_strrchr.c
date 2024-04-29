/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:20:18 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 16:37:19 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	_ft_strrchr_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = _ft_strrchr_strlen(s);
	while (s[len] != (char) c)
	{
		if (len == 0)
			break ;
		len--;
	}
	if (s[len] != (char) c)
		return (0);
	return ((char *)(s + len));
}
