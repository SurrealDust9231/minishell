/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:28:10 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 14:16:07 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../unittests.h"

void	ut_rl_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	// rl_replace_line("", 1);
	rl_redisplay();
}
