/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:30:07 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 19:53:55 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pwd.h"

int	main(int ac, char **av)
{
	char	cwd[1024];

	if (ac != 1)
		return (ft_puterr_return(\
				"pwd: too many arguments\n", -1));
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (ft_error_return(av[0], -1));
	printf("%s\n", cwd);
	return (0);
}
