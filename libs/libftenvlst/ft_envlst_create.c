/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 19:47:34 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

t_envlst	*ft_envlst_create(void)
{
	t_envlst	*rt;

	rt = (t_envlst *) malloc(sizeof(t_envlst));
	if (rt == NULL)
		return (NULL);
	rt->key = NULL;
	rt->value = NULL;
	rt->next = NULL;
	return (rt);
}
