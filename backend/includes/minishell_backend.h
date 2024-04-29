/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_backend.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:27 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 18:45:00 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BACKEND_H
# define MINISHELL_BACKEND_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <libft.h>
# include <libftast.h>
# include <libftend.h>

int		mbe_search_path(char **path, char *file_path);
int		mbe_external_cmd(t_astree *node);
void 	mbe_simple_cmd(t_astree *node);

#endif
