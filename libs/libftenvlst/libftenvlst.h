/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftenvlst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:57:38 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTENVLST_H
# define LIBFTENVLST_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_envlst	t_envlst;
struct	s_envlst
{
	char		*key;
	char		*value;
	t_envlst	*prev;
	t_envlst	*next;
};

typedef struct s_minsh	t_minsh;
struct	s_minsh
{
	t_envlst	*elst;
	int			status;
};

t_envlst	*ft_envlst_create(char *key, char *value);
int			ft_envlst_init(t_envlst **elst, char **envs);
void		ft_envlst_delone(t_envlst **elst, char *key);
void		*ft_envlst_destroy_node(t_envlst **elst);
void		ft_envlst_destroy(t_envlst **elst);
char		*ft_envlst_get(t_envlst *elst, char *key);
t_envlst	*ft_envlst_get_node(t_envlst *elst, char *key);
void		ft_envlst_push(t_envlst **elst, t_envlst *node);
void		ft_envlst_showall(t_envlst *elst);
void		ft_envlst_showall_ascii(t_envlst *elst);
int			ft_envlst_set(t_envlst **elst, char *key, char *value);

int			ft_minsh_init(t_minsh **minsh, char **envs);
void		ft_minsh_destroy(t_minsh *minsh);

#endif
