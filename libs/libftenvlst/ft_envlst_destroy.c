/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 23:59:55 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

void	*ft_envlst_destroy_node(t_envlst **elst)
{
	if (*elst == NULL)
		return ;
	if ((*elst)->key != NULL)
		free((*elst)->key);
	if ((*elst)->value != NULL)
		free((*elst)->value);
	(*elst)->key = NULL;
	(*elst)->value = NULL;
	(*elst)->prev = NULL;
	(*elst)->next = NULL;
	free(*elst);
	*elst = NULL;
	return (NULL);
}

static void	_ft_envlst_destroy_prev(t_envlst **elst)
{
	if (*elst == NULL)
		return ;
	_ft_envlst_destroy_prev(&(*elst)->prev);
	ft_envlst_destroy_node(elst);
}

static void	_ft_envlst_destroy_next(t_envlst **elst)
{
	if (*elst == NULL)
		return ;
	_ft_envlst_destroy_next(&(*elst)->next);
	ft_envlst_destroy_node(elst);
}

void	ft_envlst_destroy(t_envlst **elst)
{
	if (*elst == NULL)
		return ;
	_ft_envlst_destroy_prev(&(*elst)->prev);
	_ft_envlst_destroy_next(&(*elst)->next);
	ft_envlst_destroy_node(elst);
}
