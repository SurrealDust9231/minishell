/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbe_pipe_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:36:11 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/30 17:09:09 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittests.h"

int	mbe_pipe_test(void)
{
	open("etsfsdf", F_ADDFILESIGS);
	ft_error_return("mbe_pipe_test", -1);
	mbe_pipe(NULL);
	return (0);
}
