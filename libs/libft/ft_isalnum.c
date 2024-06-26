/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:51:48 by chang-pa          #+#    #+#             */
/*   Updated: 2024/02/12 22:39:21 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c > 057 && c < 072)
		return (1);
	else if (c > 0100 && c < 0133)
		return (1);
	else if (c > 0140 && c < 0173)
		return (1);
	return (0);
}
