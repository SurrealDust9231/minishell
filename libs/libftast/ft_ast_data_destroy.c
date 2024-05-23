/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_data_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:42:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 19:07:22 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"

void	ft_ast_data_destroy(void **data, t_ttype type)
{
	char	**args;

	if (type == TK_COMMAND || type == TK_REDIRECT_OUT
		|| type == TK_REDIRECT_IN || type == TK_REDIRECT_HEREDOC
		|| type == TK_REDIRECT_APPEND)
	{
		args = *data;
		if (args)
		{
			free(args[0]);
			free(args);
		}
	}
	*data = NULL;
}
