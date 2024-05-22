/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 11:19:30 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

void	ft_envlst_push(t_envlst **elst, t_envlst *node)
{
	if (node == NULL)
		return ;
	if (*elst == NULL)
		*elst = node;
	else if ((*elst)->next == NULL)
	{
		(*elst)->next = node;
		node->prev = *elst;
	}
	else
		ft_envlst_push(&(*elst)->next, node);
}
