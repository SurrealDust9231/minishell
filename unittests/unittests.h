/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:02:47 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 18:10:15 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTESTS_H
# define UNITTESTS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

# include <term.h>

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <libft.h>
# include <libftast.h>
# include <minishell_backend.h>

# define ERROR			-1
# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_UP			4283163
# define KEY_DOWN		4348699
# define KEY_BACKSPACE	127
# define CURPOS			"\033[6n"

void	ftast_test(void);
void	ncurses_test(void);
void	readline_test(void);
int		mbes_test(int ac, char **av);

#endif
