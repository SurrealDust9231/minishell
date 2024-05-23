/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minsh_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:16:40 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 21:17:57 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftenvlst.h"

void	ft_minsh_destroy(t_minsh *minsh)
{
	if (minsh == NULL)
		return ;
	if (minsh->elst != NULL)
		ft_envlst_destroy(&minsh->elst);
	free(minsh);
}
