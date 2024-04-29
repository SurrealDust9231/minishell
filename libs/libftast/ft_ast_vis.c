/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_vis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:19:14 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 16:24:29 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"
#include <stdio.h>

static void	_ft_ast_vis_m(t_astree *ast, \
	char m[50][50], int p, int n)
{
	char		c;

	if (ast == NULL)
		return ;
	if (ast->type == TK_NULL)
		c = 'N';
	if (ast->type == TK_COMMAND)
		c = 'C';
	if (ast->type == TK_PIPE)
		c = 'P';
	m[p][n] = c;
	_ft_ast_vis_m(ast->l, m, p - p / 2, n + 1);
	_ft_ast_vis_m(ast->r, m, p + p / 2, n + 1);
}

void	ft_ast_vis(t_astree *ast)
{
	char	m[50][50];
	int		r;
	int		c;

	if (ast == NULL)
		return ;
	r = 0;
	while (r < 50)
	{
		c = 0;
		while (c < 50)
			m[c++][r] = ' ';
		r++;
	}
	_ft_ast_vis_m(ast, m, 25, 0);
	r = 0;
	while (r < 20)
	{
		c = 0;
		while (c < 50)
			printf("%c", m[c++][r]);
		printf("\n");
		r++;
	}
}
