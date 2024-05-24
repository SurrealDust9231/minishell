/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:51:00 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 14:30:39 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static int	_mberh_read_in_stdin(t_minsh *minsh, int fd, char *delim)
{
	char	*buf;

	(void) minsh;
	while (1)
	{
		buf = NULL;
		buf = readline("> ");
		if (!buf)
		{
			ft_error_msg("warning: here-document delimited by end-of-file ");
			ft_error_msg("(wanted '");
			ft_error_msg(delim);
			ft_error_msg("')\n");
			break ;
		}
		if (mb_executor_heredoc_expand(&buf, minsh) != 0)
			return (-1);
		if (!ft_strcmp(delim, buf))
			break ;
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	free(buf);
	return (1);
}

static int	_mberh_heredoc(char	**args, \
	pid_t pid, int fds[2], t_minsh *minsh)
{
	if (pid == 0)
	{
		close(fds[0]);
		_mberh_read_in_stdin(minsh, fds[1], args[0]);
		close(fds[1]);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		return (ft_error_return("_mberh_heredoc: ", -1));
	return (0);
}

static int	_mberh_left(t_astree *left, \
	pid_t pid, int fds[2], t_minsh *minsh)
{
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		mbe_execute_node(left, minsh);
		exit(minsh->status);
	}
	else if (pid < 0)
		return (ft_error_return("_mberh_left: ", -1));
	return (0);
}

int	mbe_redirect_heredoc(t_astree *node, t_minsh *minsh)
{
	int		fds[2];
	pid_t	pid[2];
	int		status;

	if (pipe(fds) == -1)
		return (ft_error_return("mbe_redirection_heredoc1: ", -1));
	pid[0] = fork();
	if (pid[0] < 1 && _mberh_heredoc(node->data, pid[0], fds, minsh) != 0)
		return (ft_error_return("mbe_redirection_heredoc2: ", -1));
	else if (pid[0] > 0)
	{
		waitpid(pid[0], &status, 0);
		pid[1] = fork();
		if (pid[1] < 1 && _mberh_left(node->l, pid[1], fds, minsh) != 0)
			return (ft_error_return("mbe_redirection_heredoc3: ", -1));
		else if (pid[1] > 0)
		{
			close(fds[0]);
			close(fds[1]);
			waitpid(pid[1], &status, 0);
			minsh->status = status / 256;
		}
	}
	return (0);
}
