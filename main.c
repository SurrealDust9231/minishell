/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:04:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/22 19:43:35 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// COMMAN'S START
// EXPAND THE $

int	main(int _ac, char **_av, char **_envs)
{
	int			i;
	int			index;
	char		*line;
	char		**av;
	char		*expanded;
	t_astree	*ast;
	t_minsh		minsh;

	(void) _ac;
	(void) _av;
	minsh.elst = NULL;
	if (ft_envlst_init(&minsh.elst, _envs) != 0)
		exit (ft_error_return("env init error", -1));
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
			mbe_execute_node(ast, &minsh);
			ft_ast_destroy(&ast);
		}
		free(av);
		free(line);
	}
	return (0);
}
