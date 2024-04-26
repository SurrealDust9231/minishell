/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:37:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/26 13:57:41 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include "libft01/libft.h"

# define MAX_ARGS 10
#define MAX_CMD_LEN 1024
#define MAX_TOKENS 100

typedef struct	s_command
{
    char	*cmd;             // command a execute
    char	**args;           // args
    char	*redirect_in;     // <, si existe
    char	*redirect_out;    // >, si existe
    char	append;           // > avec append
}	t_command;

typedef struct	s_pipeline
{
    t_command	**commands;   // Array de command dans la pipeline
    int			num_commands; // Numero de command dans la pipeline
}	t_pipeline;

size_t	ft_strlen(const char *s);

char	**custom_split(char *str);
char	**ft_split(char const *s, char c);

#endif