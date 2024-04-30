/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:41:58 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 12:55:14 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int mbe_simple_cmd(t_astree *node)
{
	if (mbe_external_cmd(node->data) != 0)
		return (-1);
	// if (ft_strcmp(args[0], "pwd") == 0)
	// {
	// 	execute_pwd();
	// }
	// else if (ft_strcmp(args[0], "echo") == 0)
	// {
	// 	execute_echo(args);
	// }
	// else if (ft_strcmp(args[0], "cd") == 0)
	// {
	// 	execute_cd(args);
	// }
	// else
	// {
	//     // more commands
	// }
	return (0);
}
