/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:02:35 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/26 19:30:28 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittests.h"

// int		main(void)
// {
// 	struct termios		t;

// 	if (!init_term(&t) || !init_query() || !read_char())
// 		return (1);
// 	return (0);
// }

int		main(void)
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
			return (1);
	}
	return (0);
}
