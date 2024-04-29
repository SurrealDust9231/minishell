/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:56:59 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 13:51:44 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	_ft_lstclear_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	lst->content = NULL;
	lst->next = NULL;
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst == NULL)
		return ;
	ft_lstclear(&((*lst)->next), del);
	_ft_lstclear_lstdelone(*lst, del);
	*lst = NULL;
}
