/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_vis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:19:14 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/28 21:39:24 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"
#include <stdio.h>

void	ft_ast_vis(t_astree *ast)
{
	printf("%p\n", ast);
	if (ast == NULL)
		return ;
	if (ast->type == TK_NULL)
		printf("(NULL)");
}
