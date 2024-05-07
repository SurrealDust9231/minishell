/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:30:07 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/06 21:51:30 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_puterr_return(\
				"cd: wrong number of arguments\n", -1));
	if (chdir(av[1]) != 0)
		return (ft_error_return(av[0], -1));
	return (0);
}
