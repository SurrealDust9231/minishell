/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:30:11 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/13 18:14:05 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static char	*_mbebs_get_subcmd(char *file_path, char *builtin_path)
{
	int		flen;
	int		plen;
	char	*path;

	flen = ft_strlen(file_path);
	plen = ft_strlen(builtin_path);
	path = (char *) malloc(sizeof(char) * (plen + 1 + flen + 1));
	if (path == NULL)
		return (NULL);
	ft_strncpy(path, builtin_path, plen);
	path[plen] = '\0';
	if (plen != 0 && builtin_path[plen - 1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, file_path);
	return (path);
}

int	mbb_search(char **path, char *file_path, char *builtin_path)
{
	struct stat	st;

	if (file_path == NULL || builtin_path == NULL)
		return (0);
	*path = _mbebs_get_subcmd(file_path, builtin_path);
	if (*path == NULL)
		return (ft_error_return("mbeb_search1", -1));
	if (stat(*path, &st) == 0 && S_ISREG(st.st_mode))
		return (0);
	free(*path);
	*path = NULL;
	return (0);
}
