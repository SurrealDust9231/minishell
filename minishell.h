/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:37:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 21:26:22 by chang-pa         ###   ########.fr       */
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

typedef void (*node_handler)(t_astree *);

typedef struct s_node_handler_mapping
{
	t_ttype			type;
	node_handler	handler;
}	t_node_handler_mapping;

char	**custom_split(char *str);

void	execute_pwd(void);
void	execute_cd(char **args);
void	execute_echo(char **args);
void	executeAST(t_astree *node);

#endif
