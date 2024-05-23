/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftend.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:29:14 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 14:28:26 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTEND_H
# define LIBFTEND_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

int		ft_error_tma_return(const char *arg, int rt);
int		ft_error_nar_return(const char *arg, const char *msg, int rt);
int		ft_error_return(const char *msg, int rt);
int		ft_puterr_return(const char *msg, int rt);
void	ft_error_cnf(const char *arg);
void	ft_error_nvi(const char *arg, const char *msg);

#endif
