/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_data_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:42:38 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 17:34:22 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftast.h"

static void	_fa_data_destroy_array_str(char **a_str)
{
	int	i;

	if (a_str == NULL)
		return ;
	i = 0;
	while (a_str[i] != 0)
		free(a_str[i++]);
	free(a_str);
}

void	ft_ast_data_destroy(void **data, t_ttype type)
{
	if (type == TK_COMMAND)
		_fa_data_destroy_array_str(*data);
	*data = NULL;
}
