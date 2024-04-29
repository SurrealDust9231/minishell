/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:01:36 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 12:13:06 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rt;

	if (lst == NULL)
		return (NULL);
	rt = (t_list *) malloc(sizeof(t_list));
	if (rt == NULL)
		return (NULL);
	rt->content = f(lst->content);
	if (lst->next != NULL)
	{
		rt->next = ft_lstmap(lst->next, f, del);
		if (rt->next == NULL)
		{
			del(rt->content);
			rt->content = NULL;
			free(rt);
			return (NULL);
		}
	}
	else
		rt->next = NULL;
	return (rt);
}
