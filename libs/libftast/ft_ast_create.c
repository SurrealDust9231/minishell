/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:04:04 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/28 21:44:01 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"

int	ft_ast_create(t_astree **ast)
{
	*ast = (t_astree *) malloc(sizeof(t_astree));
	if (*ast == NULL)
		return (-1);
	(*ast)->data = NULL;
	(*ast)->l = NULL;
	(*ast)->r = NULL;
	(*ast)->type = TK_NULL;
	return (0);
}
