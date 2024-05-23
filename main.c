/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:04:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/22 21:44:48 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_cmd_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

static void	handle_global_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_cmd_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_cmd_signal);
}

void	handle_global_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_global_signal);
}

int	main(int _ac, char **_av, char **_envs)
{
	int			i;
	int			index;
	char		*line;
	char		**av;
	char		*expanded;
	t_astree	*ast;
	t_minsh		*minsh;

	(void) _ac;
	(void) _av;
	handle_global_signals();
	if (ft_minsh_init(&minsh, _envs) != 0)
		exit (ft_error_return("env init error", -1));
	while (1)
	{
		line = readline("minishell&> ");
		if (line == NULL)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		add_history(line);
		av = custom_split(line);
		if (!av)
		{
			free(line);
			continue ;
		}
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			free(av);
			break ;
		}
		i = 0;
		while (av[i] != NULL)
		{
			expanded = expand_variables(av[i], minsh);
			free(av[i]);
			av[i] = expanded;
			i++;
		}
		index = 0;
		ast = parse_commands(av, &index);
		if (ast)
		{
			handle_cmd_signals();
			mbe_execute_node(ast, minsh);
			handle_global_signals();
			ft_ast_destroy(&ast);
		}
		free(av);
		free(line);
	}
	ft_minsh_destroy(minsh);
	return (0);
}
