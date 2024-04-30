/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:41:58 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:47:52 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbe_simple_cmd(t_astree *node)
{
	if (mbe_external_cmd(node->data) != 0)
		return (ft_error_return("mbe_external_cmd", -1));
	return (0);
}
