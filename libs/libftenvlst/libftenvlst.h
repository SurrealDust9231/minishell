/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftenvlst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 23:29:56 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTENVLST_H
# define LIBFTENVLST_H

# include <stdlib.h>

typedef struct s_envlst	t_envlst;
struct	s_envlst
{
	char		*key;
	char		*value;
	t_envlst	*prev;
	t_envlst	*next;
};

t_envlst	*ft_envlst_create(char *key, char *value);
int			ft_envlst_init(t_envlst **elst);
void		ft_envlst_delone(t_envlst **elst, char *key);
void		*ft_envlst_destroy_node(t_envlst **elst);
void		ft_envlst_destroy(t_envlst **elst);
char		*ft_envlst_get(t_envlst *elst, char *key);
int			ft_envlst_push(t_envlst **elst, char *key, char *value);
int			ft_envlst_showall(t_envlst *elst);

#endif
