/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:04:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/05/23 21:57:46 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_minishell_get_args(t_msst *msst)
{
	msst->line = readline("minishell&> ");
	if (msst->line == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		return (-1);
	}
	add_history(msst->line);
	msst->expanded = expand_variables(msst->line, msst->minsh);
	if (msst->expanded == NULL)
		return (-1);
	custom_split(msst->expanded, &msst->state);
	return (0);
}

static int	_minishell_parsing_ast(t_msst *msst)
{
	msst->index = 0;
	msst->ast = parse_commands(msst->state.result, &msst->index);
	if (msst->ast)
	{
		handle_cmd_signals();
		mbe_execute_node(msst->ast, msst->minsh);
		handle_global_signals();
		ft_ast_destroy(&msst->ast);
	}
	return (0);
}

static int	_minishell_cleanup_cache(t_msst *msst)
{
	if (msst->line != NULL)
		free(msst->line);
	if (msst->expanded != NULL)
		free(msst->expanded);
	cleanup_split_state(&msst->state);
	return (1);
}

int	main(int ac, char **av, char **_envs)
{
	t_msst	msst;

	if (ac != 1 || av == NULL)
		return (0);
	handle_global_signals();
	if (ft_minsh_init(&msst.minsh, _envs) != 0)
		exit (ft_error_return("env init error", -1));
	while (1)
	{
		if (_minishell_get_args(&msst) != 0)
			break ;
		if (!msst.state.result && _minishell_cleanup_cache(&msst))
			continue ;
		if (_minishell_parsing_ast(&msst) != 0 && _minishell_cleanup_cache(&msst))
			break ;
		_minishell_cleanup_cache(&msst);
	}
	ft_minsh_destroy(msst.minsh);
	return (0);
}
