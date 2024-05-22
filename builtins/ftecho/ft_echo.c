/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:30:07 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/21 19:53:48 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"

static int	_ftecho_return(int r, int n_flag)
{
	if (!n_flag)
		write(STDOUT_FILENO, "\n", 1);
	return (r);
}

static void	_ftecho_printstr(char *s, int q_flag)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	if (q_flag)
	{
		len--;
		i++;
	}
	while (i < len)
		write(STDOUT_FILENO, s + i++, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	flag[2];

	i = 1;
	flag[0] = 0;
	flag[1] = 0;
	if (ac < 2)
		return (_ftecho_return(0, flag[0]));
	if (ft_strcmp(av[1], "-n") == 0)
		i += ++flag[0];
	while (av[i])
	{
		if ((av[i][0] == '\"' && av[i][ft_strlen(av[i]) - 1] == '\"') ||
			(av[i][0] == '\'' && av[i][ft_strlen(av[i]) - 1] == '\''))
			flag[1] = 1;
		_ftecho_printstr(av[i], flag[1]);
		if (av[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	return (_ftecho_return(0, flag[0]));
}
