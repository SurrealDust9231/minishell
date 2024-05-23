/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_execute_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 20:36:57 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbe_execute_node(t_astree *node, t_minsh *minsh)
{
	if (node == NULL)
		return (0);
	if (node->type == TK_COMMAND \
		&& mbe_simple_cmd(node, node->data, minsh) != 0)
		return (-1);
	else if (node->type == TK_PIPE && mbe_pipe(node, minsh) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_IN && mbe_redirect_in(node, minsh) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_OUT \
		&& mbe_redirect_out(node, minsh) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_APPEND \
		&& mbe_redirect_append(node, minsh) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_HEREDOC \
		&& mbe_redirect_heredoc(node, minsh) != 0)
		return (-1);
	return (0);
}
