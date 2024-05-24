/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:55:54 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 13:11:45 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

int	mbe_redirect_out(t_astree *node, t_minsh *minsh)
{
	int	original_stdout;
	int	fd;

	original_stdout = dup(STDOUT_FILENO);
	fd = open(((char **)node->data)[0], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_error_return("mbe_redirect_out", -1));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	mbe_execute_node(node->l, minsh);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (0);
}

int	mbe_redirect_append(t_astree *node, t_minsh *minsh)
{
	int	original_stdout;
	int	fd;

	original_stdout = dup(STDOUT_FILENO);
	fd = open(((char **)node->data)[0], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (ft_error_return("mbe_redirect_append", -1));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	mbe_execute_node(node->l, minsh);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (0);
}

int	mbe_redirect_in(t_astree *node, t_minsh *minsh)
{
	int	original_stdin;
	int	fd;

	original_stdin = dup(STDIN_FILENO);
	fd = open(((char **)node->data)[0], O_RDONLY);
	if (fd == -1)
		return (ft_error_return("mbe_redirect_in", -1));
	dup2(fd, STDIN_FILENO);
	close(fd);
	mbe_execute_node(node->l, minsh);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	return (0);
}
