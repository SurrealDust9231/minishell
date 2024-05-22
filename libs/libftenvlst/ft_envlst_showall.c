/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlst_showall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:43:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 12:24:27 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

void	ft_envlst_showall(t_envlst *elst)
{
	while (elst != NULL)
	{
		printf("%s=%s\n", elst->key, elst->value);
		elst = elst->next;
	}
}
