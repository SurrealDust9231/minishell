/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:28:10 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 16:20:05 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../unittests.h"

static void	ut_rl_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	// rl_replace_line("", 1);
	rl_redisplay();
}

void	ncurses_test(void)
{
	int				ret;
	char			*line;

	signal(SIGINT, ut_rl_handler);
	while (true)
	{
		line = readline("input> ");
		if (line)
		{
			ret = strcmp(line, "bye");
			if (ret)
				printf("output> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
			if (!ret)
				break ;
		}
		else
			return ;
	}
}
