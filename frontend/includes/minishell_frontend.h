/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_frontend.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 00:20:55 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FRONTEND_H
# define MINISHELL_FRONTEND_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <libft.h>
# include <libftast.h>
# include <libftenvlst.h>

typedef struct s_split_state
{
	char	**result;
	char	result_buf[1024];
	char	token[1024];
	int		in_single_quote;
	int		in_double_quote;
	int		token_index;
	int		result_index;
	int		i;
}			t_split_state;

typedef struct s_expantion_context
{
	int		i;
	int		result_idx;
	int		in_single_quote;
	int		in_double_quote;
	char	*result;
	char	*token;
}	t_expantion_context;

typedef struct s_result_context
{
	char	*result;
	int		*result_idx;
}			t_result_context;

int			custom_split(char *str, t_split_state *state);
char		*expand_variables(char *token, t_minsh *minsh);
t_astree	*parse_commands(char **tokens, int *index);

void		init_split_state(t_split_state *state);
void		add_token_if_needed(t_split_state *state);
void		cleanup_split_state(t_split_state *state);
int			quote_state(int current_state, int in_other_quote);
void		copy_var_value(char *result,
				int *result_idx, const char *var_value);

t_astree	*create_red_node(char **tokens,
				int *index, t_astree *left, int type);
t_astree	*handle_redirect_tokens(char **tokens, int *index, t_astree *left);

#endif
