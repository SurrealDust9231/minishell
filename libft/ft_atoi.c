/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:11:18 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/13 16:25:12 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				sign;

	while (*str != 0 && ((*str > 8 && *str < 14) || *str == 32))
		str++;
	n = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != 0 && (*str > 057 && *str < 072))
	{
		n = 10 * n + *str - '0';
		str++;
	}
	return (n * sign);
}
