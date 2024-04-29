/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftast_vis_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:55 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 16:05:58 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittests.h"

void	ftast_test(void)
{
	t_astree	*ast;
	t_astree	*node;

	ft_ast_create(&ast);
	ft_ast_init(ast, TK_PIPE, NULL);
	ft_ast_create(&node);
	ft_ast_init(node, TK_COMMAND, NULL);
	ast->l = node;
	ft_ast_create(&node);
	ft_ast_init(node, TK_NULL, NULL);
	ast->r = node;
	ft_ast_vis(ast);
}
