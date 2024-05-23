/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_showall_ascii.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 19:56:01 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

static int	_ft_envlst_sascii_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static void	_ft_envlst_sascii_sort(char **keys, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (_ft_envlst_sascii_strcmp(keys[i], keys[j]) > 0)
			{
				tmp = keys[i];
				keys[i] = keys[j];
				keys[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	_ft_envlst_sascii_print(char **keys, t_envlst *elst)
{
	while (*keys)
	{
		printf("%s=%s\n", *keys, ft_envlst_get(elst, *keys));
		keys++;
	}
}

void	ft_envlst_showall_ascii(t_envlst *elst)
{
	size_t		len;
	char		**keys;
	t_envlst	*tmp;

	len = ft_envlst_size(elst);
	keys = (char **) malloc(sizeof(char *) * (len + 1));
	keys[len] = NULL;
	tmp = elst;
	len = 0;
	while (tmp != NULL)
	{
		keys[len++] = tmp->key;
		tmp = tmp->next;
	}
	_ft_envlst_sascii_sort(keys, len);
	_ft_envlst_sascii_print(keys, elst);
	free(keys);
}
