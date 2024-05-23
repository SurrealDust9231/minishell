/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:20:40 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 19:32:45 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

static int	_ft_envlst_set_push(t_envlst **elst, char *key, char *value)
{
	t_envlst	*node;

	node = ft_envlst_create(key, value);
	if (node == NULL)
		return (-1);
	ft_envlst_push(elst, node);
	return (0);
}

size_t	_ft_envlst_set_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

void	_ft_envlst_set_strcpy(char *dst, char *src)
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

int	ft_envlst_set(t_envlst **elst, char *key, char *value)
{
	t_envlst	*node;
	size_t		len;

	if (key == NULL || value == NULL)
		return (-1);
	if (*elst == NULL)
		return (_ft_envlst_set_push(elst, key, value));
	node = ft_envlst_get_node(*elst, key);
	if (node == NULL)
		return (_ft_envlst_set_push(elst, key, value));
	free(node->value);
	len = _ft_envlst_set_strlen(value);
	node->value = (char *) malloc(sizeof(char) * (len + 1));
	if (node->value == NULL)
		return (-1);
	_ft_envlst_set_strcpy(node->value, value);
	return (0);
}
