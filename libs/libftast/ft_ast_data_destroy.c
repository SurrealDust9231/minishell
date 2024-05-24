/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_data_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:42:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 22:08:31 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"

void	ft_ast_data_destroy(void **data, t_ttype type)
{
	char	**args;
	int		i;

	if (type == TK_COMMAND || type == TK_REDIRECT_OUT
		|| type == TK_REDIRECT_IN || type == TK_REDIRECT_HEREDOC
		|| type == TK_REDIRECT_APPEND)
	{
		args = *data;
		if (args)
		{
			i = 0;
			while (args[i])
				free(args[i++]);
			free(args);
		}
	}
	*data = NULL;
}
