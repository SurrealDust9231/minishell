/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:04:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 00:54:31 by chang-pa         ###   ########.fr       */
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
	int				i;
	int				index;
	char			*line;
	char			**av;
	char			*expanded;
	t_astree		*ast;
	t_minsh			*minsh;
	t_split_state	state;

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
		expanded = expand_variables(line, minsh);
		custom_split(expanded, &state);
		if (!state.result)
		{
			free(line);
			free(expanded);
			cleanup_split_state(&state);
			continue ;
		}
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			free(expanded);
			cleanup_split_state(&state);
			break ;
		}
		index = 0;
		ast = parse_commands(state.result, &index);
		if (ast)
		{
			handle_cmd_signals();
			mbe_execute_node(ast, minsh);
			handle_global_signals();
			ft_ast_destroy(&ast);
		}
		cleanup_split_state(&state);
		free(line);
		free(expanded);
	}
	ft_minsh_destroy(minsh);
	return (0);
}
