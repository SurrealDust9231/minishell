/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:38:50 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/28 20:40:45 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"

void	ft_ast_init(t_astree *ast, t_ttype type, char **data)
{
	if (ast == NULL)
		return ;
	ast->type = type;
	ast->data = data;
}
