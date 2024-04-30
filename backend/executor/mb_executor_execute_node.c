/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_execute_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:11:34 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbe_execute_node(t_astree *node)
{
	if (node == NULL)
		return (0);
	if (node->type == TK_COMMAND && mbe_simple_cmd(node) != 0)
		return (-1);
	else if (node->type == TK_PIPE && mbe_pipe(node) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_IN && mbe_redirect_in(node) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_OUT && mbe_redirect_out(node) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_APPEND \
		&& mbe_redirect_append(node) != 0)
		return (-1);
	else if (node->type == TK_REDIRECT_HEREDOC \
		&& mbe_redirect_heredoc(node) != 0)
		return (-1);
	return (0);
}
