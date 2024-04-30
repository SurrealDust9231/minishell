/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:04:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/30 18:47:12 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// COMMAN'S START
// EXPAND THE $

int	main(void)
{
	int			i;
	int			index;
	char		*line;
	char		**av;
	char		*expanded;
	t_astree	*ast;

	while (1)
	{
		line = readline("WRITE YOUR COMMAND: ");
		if (line == NULL)
			break ;
		add_history(line);
		printf("test\n");
		av = custom_split(line);
		if (!av)
		{
			printf("test\n");
			free(line);
			continue ;
		}
		printf("The line is: %s\n", line);
		printf("Comand and args:\n");
		i = 0;
		while (av[i] != NULL)
			printf("%s\n", av[i++]);
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		i = 0;
		while (av[i] != NULL)
		{
			expanded = expand_variables(av[i]);
			free(av[i]);
			av[i] = expanded;
			i++;
		}
		index = 0;
		ast = parse_commands(av, &index);
		if (ast)
		{
			mbe_execute_node(ast);
			// freeAST(ast);
		}
		free(av);
		free(line);
	}
	return (0);
}
