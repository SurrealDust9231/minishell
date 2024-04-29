/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:37:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/28 20:31:12 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>

typedef enum s_node_type
{
    NODE_COMMAND,
    NODE_PIPE,
    NODE_REDIRECT_IN,
	NODE_REDIRECT_HEREDOC,
    NODE_REDIRECT_OUT,
    NODE_REDIRECT_APPEND,
    NODE_SEQUENCE
} t_node_type;

typedef struct s_node
{
    t_node_type type;
    char **args;   // Para comandos, argumentos
    struct s_node *left;
    struct s_node *right;
} t_node;

typedef void (*node_handler)(t_node *);

typedef struct s_node_handler_mapping
{
	t_node_type		type;
	node_handler	handler;
}	t_node_handler_mapping;

size_t	ft_strlen(const char *s);

char	**custom_split(char *str);
char	**ft_split(char const *s, char c);

void	execute_pwd(void);
void	execute_cd(char **args);
void	execute_echo(char **args);
void	executeAST(t_node *node);

t_node	*createNode(t_node_type type, char **args);
t_node	*parseCommands(char **tokens, int *index);

#endif
