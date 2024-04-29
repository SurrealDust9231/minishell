/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:55:22 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/28 20:10:55 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTAST_H
# define LIBFTAST_H

# include <stdlib.h>

typedef enum e_token_type
{
	T_END			= -1,
	T_NULL			= 0,
	T_WORD,
	T_ASSIGNMENT_WORD,
	T_RED_IN,
	T_RED_OUT,
	T_PIPE,
	T_HERE_DOC,
	T_APPEND,
	T_OR,
	T_AND,
	T_L_BRACKET,
	T_R_BRACKET
}	t_ttype;

typedef struct s_astree	t_astree;
struct s_astree
{
	t_ttype		type;
	void		*data;
	t_astree	*l;
	t_astree	*r;
};

int		ft_ast_create(t_astree **ast);
void	ft_ast_destroy(t_astree **ast);

#endif
