/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbe_simple_cmd_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:32:43 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 18:10:44 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittests.h"

int	mbes_test(int ac, char **av)
{
	t_astree	*ast;

	ft_ast_create(&ast);
	ft_ast_init(ast, TK_COMMAND, ft_split(av[1], av[2][0]));
	if (mbe_simple_cmd(ast) != 0)
		return (-1);
	ft_ast_destroy(&ast);
	return (0);
}
