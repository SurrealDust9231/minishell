/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:37:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/22 12:16:26 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <term.h>
# include <libft.h>
# include <libftast.h>
# include <libftenvlst.h>
# include <minishell_frontend.h>
# include <minishell_backend.h>

typedef struct s_minsh	t_minsh;
struct	s_minsh
{
	t_envlst	*elst;
};

#endif
