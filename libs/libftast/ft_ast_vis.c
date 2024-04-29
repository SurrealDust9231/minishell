/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_vis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:19:14 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 14:18:12 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"
#include <stdio.h>

void	ft_ast_vis(t_astree *ast, int p, int n)
{
	int	i;

	if (ast == NULL || p < 0 || n < 0)
		return ;
	i = 0;
	while (i++ < p)
		printf(" ");
	if (ast->type == TK_NULL)
		printf("N");
	if (ast->type == TK_COMMAND)
		printf("C");
	if (ast->type == TK_PIPE)
		printf("P");
	printf("\n");
	ft_ast_vis(ast->l, p - n, n / 2);
	ft_ast_vis(ast->r, p + n, n / 2);
}
