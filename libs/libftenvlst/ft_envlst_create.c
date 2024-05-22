/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 23:55:53 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

size_t	_ft_envlst_create_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

void	_ft_envlst_create_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
}

t_envlst	*ft_envlst_create(char *key, char *value)
{
	t_envlst	*rt;
	size_t		len;

	rt = (t_envlst *) malloc(sizeof(t_envlst));
	if (rt == NULL || key == NULL || value == NULL)
		return (NULL);
	len = _ft_envlst_create_strlen(key);
	rt->key = (char *) malloc(sizeof(char) * (len + 1));
	if (rt->key == NULL)
		return (ft_envlst_destroy_node(&rt));
	_ft_envlst_create_strcpy(rt->key, key);
	len = _ft_envlst_create_strlen(value);
	rt->value = (char *) malloc(sizeof(char) * (len + 1));
	if (rt->value == NULL)
		return (ft_envlst_destroy_node(&rt));
	_ft_envlst_create_strcpy(rt->value, value);
	rt->prev = NULL;
	rt->next = NULL;
	return (rt);
}
