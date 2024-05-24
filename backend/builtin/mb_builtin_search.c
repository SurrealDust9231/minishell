/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_builtin_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:30:11 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/23 21:25:39 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static char	*_mbbs_get_subcmd(char *file_path, char *builtin_path)
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

static int	_mbbs_selector_path(char **path, \
	char *file_path, char *str, size_t len)
{
	if (ft_strcmp(file_path, str) != 0)
		return (0);
	*path = (char *) malloc(sizeof(char) * (len + 1));
	if (*path == NULL)
		return (-1);
	(*path)[len] = '\0';
	ft_strncpy(*path, str, len);
	return (0);
}

static int	_mbbs_selector(char **path, char *file_path)
{
	*path = NULL;
	if (_mbbs_selector_path(path, file_path, "cd", 2) != 0)
		return (-1);
	if (_mbbs_selector_path(path, file_path, "exit", 4) != 0)
		return (-1);
	if (_mbbs_selector_path(path, file_path, "env", 3) != 0)
		return (-1);
	if (_mbbs_selector_path(path, file_path, "export", 6) != 0)
		return (-1);
	if (_mbbs_selector_path(path, file_path, "unset", 5) != 0)
		return (-1);
	if (_mbbs_selector_path(path, file_path, "echo", 4) != 0)
		return (-1);
	return (0);
}

int	mbb_search(char **path, char *file_path, char *builtin_path)
{
	struct stat	st;

	if (file_path == NULL || builtin_path == NULL)
		return (0);
	if (_mbbs_selector(path, file_path) != 0)
		return (ft_error_return("mbeb_search1", -1));
	if (*path != NULL)
		return (0);
	*path = _mbbs_get_subcmd(file_path, builtin_path);
	if (*path == NULL)
		return (ft_error_return("mbeb_search2", -1));
	if (stat(*path, &st) == 0 && S_ISREG(st.st_mode))
		return (0);
	free(*path);
	*path = NULL;
	return (0);
}
