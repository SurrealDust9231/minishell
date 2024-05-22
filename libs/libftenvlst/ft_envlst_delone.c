/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_delone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 23:29:11 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

static int	_ft_envlst_delone_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_envlst_delone(t_envlst **elst, char *key)
{
	t_envlst	*tmp;

	if (*elst == NULL)
		return ;
	if (_ft_envlst_delone_strcmp((*elst)->key, key) == 0)
	{
		tmp = *elst;
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		*elst = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		ft_envlst_destroy_node(&tmp);
		ft_envlst_delone(elst, key);
	}
	else
		ft_envlst_delone(&(*elst)->next, key);
}
