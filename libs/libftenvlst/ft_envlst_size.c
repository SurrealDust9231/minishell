/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:05:05 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 18:07:24 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

size_t	ft_envlst_size(t_envlst *elst)
{
	if (elst == NULL)
		return (0);
	return (ft_envlst_size(elst->next) + 1);
}
