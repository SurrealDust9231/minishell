/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:55:22 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 16:02:51 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTAST_H
# define LIBFTAST_H

# include <stdlib.h>

typedef enum e_token_type
{
	TK_END			= -1,
	TK_NULL		= 0,
    TK_COMMAND,
    TK_PIPE,
    TK_REDIRECT_IN,
	TK_REDIRECT_HEREDOC,
    TK_REDIRECT_OUT,
    TK_REDIRECT_APPEND,
    TK_SEQUENCE
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
void	ft_ast_data_destroy(void *data, t_ttype type);
void	ft_ast_init(t_astree *ast, t_ttype type, char **data);
void	ft_ast_vis(t_astree *ast);

#endif
