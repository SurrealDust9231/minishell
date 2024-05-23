/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:37:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 13:27:56 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <term.h>
# include <libft.h>
# include <libftast.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <libftenvlst.h>
# include <minishell_frontend.h>
# include <minishell_backend.h>

typedef struct s_msst	t_msst;

struct s_msst
{
	int				index;
	char			*line;
	char			*expanded;
	t_astree		*ast;
	t_minsh			*minsh;
	t_split_state	state;
};

void		handle_cmd_signals(void);
void		handle_global_signals(void);

#endif
