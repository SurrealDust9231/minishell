/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:37:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/22 19:25:54 by saguayo-         ###   ########.fr       */
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

typedef struct s_minsh	t_minsh;
struct	s_minsh
{
	t_envlst	*elst;
};

#endif
