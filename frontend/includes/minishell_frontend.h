/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_frontend.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 19:21:09 by saguayo-         ###   ########.fr       */
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

typedef struct s_split_state
{
	char	**result;
	char	*token;
	int		in_single_quote;
	int		in_double_quote;
	int		token_index;
	int		result_index;
	int		i;
}			t_split_state;

typedef struct s_expansion_state
{
	char	*result;
	char	var_name[256];
	int		i;
	int		result_idx;
	int		var_idx;
	int		in_single_quote;
	int		in_double_quote;
}			t_expansion_state;

char		**custom_split(char *str);
char		*expand_variables(char *token);
t_astree	*parse_commands(char **tokens, int *index);

#endif
