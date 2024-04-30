/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:49:47 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:54:59 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

// ECHO && ECHO -N
int	mbb_echo(char **args)
{
	int i = 1;
	int n_flag = 0;

	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n_flag = 1;
		i = 2;
	}
	while (args[i])
	{
		if ((args[i][0] == '\"' && args[i][strlen(args[i]) - 1] == '\"') ||
			(args[i][0] == '\'' && args[i][strlen(args[i]) - 1] == '\''))
		{
			args[i][strlen(args[i]) - 1] = '\0';
			printf("%s", args[i] + 1);
		}
		else
			printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	return (0);
}
