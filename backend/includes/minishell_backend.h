/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_backend.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/24 14:07:16 by chang-pa         ###   ########.fr       */
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
# include <readline/readline.h>

# ifndef MINISHELL_ROOT_DIR
#  define MINISHELL_ROOT_DIR 0
# endif

typedef struct s_heredoc_context
{
	int		i;
	int		result_idx;
	int		in_single_quote;
	int		in_double_quote;
	char	*result;
	char	*token;
}	t_heredoc_context;

typedef struct s_heredoc_rcontext
{
	char	*result;
	int		*result_idx;
}	t_heredoc_rcontext;

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
int		mbb_cmd_echo(char **av, t_minsh *minsh);
int		mbb_cmd(char **av, char *path, t_minsh *minsh);

int		mb_executor_heredoc_expand(char **token, t_minsh *minsh);
int		mbehe_quote_state(int current_state, int in_other_quote);
void	mbehe_copy_var_value(char *result, \
	int *result_idx, const char *var_value);

#endif
