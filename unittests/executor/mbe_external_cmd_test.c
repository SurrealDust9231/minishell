/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbe_external_cmd_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:32:43 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 12:50:17 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittests.h"

int	mbe_external_cmd_test(void)
{
	t_astree	*ast;

	ft_ast_create(&ast);
	ft_ast_init(ast, TK_COMMAND, ft_split("ls -la", ' '));
	if (mbe_external_cmd(ast->data) != 0)
		return (-1);
	ft_ast_destroy(&ast);
	return (0);
}
