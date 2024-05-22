/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_backend.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 19:53:36 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BACKEND_H
# define MINISHELL_BACKEND_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <libft.h>
# include <libftast.h>
# include <libftend.h>

# ifndef MINISHELL_ROOT_DIR
#  define MINISHELL_ROOT_DIR 0
# endif

int		mbe_execute_node(t_astree *node);
int		mbe_simple_cmd(t_astree *node);
int		mbe_pipe(t_astree *node);
int		mbe_redirect_out(t_astree *node);
int		mbe_redirect_append(t_astree *node);
int		mbe_redirect_in(t_astree *node);
int		mbe_redirect_heredoc(t_astree *node);

int		mbn_search(char **path, char *file_path);
int		mbn_cmd(char **av, char *path);
int		mbb_search(char **path, char *file_path, char *builtin_path);
int		mbb_cmd_cd(char **av);
int		mbb_cmd_exit(char **av);
int		mbb_cmd(char **av, char *path);

#endif
