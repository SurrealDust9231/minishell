/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:02:35 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:05:03 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittests.h"

int	main(int ac, char **av)
{
	// printf("mbes_test: %d\n", mbe_external_cmd_test());
	mbe_pipe_test();
	// ftast_test();
	// readline_test();
	// ncurses_test();
	return (0);
}
