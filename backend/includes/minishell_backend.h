/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_backend.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:29:20 by chang-pa         ###   ########.fr       */
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
# include <libftenvlst.h>

# ifndef MINISHELL_ROOT_DIR
#  define MINISHELL_ROOT_DIR 0
# endif

int		mbe_execute_node(t_astree *node, t_minsh *minsh);
int		mbe_simple_cmd(t_astree *node, char **av, t_minsh *minsh);
int		mbe_pipe(t_astree *node, t_minsh *minsh);
int		mbe_redirect_out(t_astree *node, t_minsh *minsh);
int		mbe_redirect_append(t_astree *node, t_minsh *minsh);
int		mbe_redirect_in(t_astree *node, t_minsh *minsh);
int		mbe_redirect_heredoc(t_astree *node, t_minsh *minsh);

int		mbn_search(char **path, char *file_path, t_minsh *minsh);
int		mbn_cmd(char **av, char *path, t_minsh *minsh);

int		mbb_search(char **path, char *file_path, char *builtin_path);
int		mbb_cmd_cd(char **av, t_minsh *minsh);
int		mbb_cmd_export(char **av, t_minsh *minsh);
int		mbb_cmd_env(char **av, t_minsh *minsh);
int		mbb_cmd_unset(char **av, t_minsh *minsh);
int		mbb_cmd_exit(char **av, t_minsh *minsh);
int		mbb_cmd(char **av, char *path, t_minsh *minsh);

#endif
