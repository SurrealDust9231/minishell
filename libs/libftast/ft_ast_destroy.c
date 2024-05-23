/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:08:13 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 18:50:34 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"

void	ft_ast_destroy(t_astree **ast)
{
	if (ast == NULL || *ast == NULL)
		return ;
	if ((*ast)->data != NULL)
		ft_ast_data_destroy(&(*ast)->data, (*ast)->type);
	(*ast)->type = 0;
	if ((*ast)->l != NULL)
		ft_ast_destroy(&(*ast)->l);
	if ((*ast)->r != NULL)
		ft_ast_destroy(&(*ast)->r);
	free(*ast);
	*ast = NULL;
}
