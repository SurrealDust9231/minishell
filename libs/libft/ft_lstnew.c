/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:41:42 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 11:43:14 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rt;

	rt = (t_list *) malloc(sizeof(t_list));
	if (rt == NULL)
		return (NULL);
	rt->next = NULL;
	rt->content = content;
	return (rt);
}
