/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_nbuiltin_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:53:01 by chang-pa          #+#    #+#             */
/*   Updated: 2024/05/22 18:10:44 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_backend.h"

static char	*_mbens_get_subcmd(size_t i[2], char *file_path, char *env_path)
{
	int		flen;
	char	*path;
	int		plen;

	flen = ft_strlen(file_path);
	i[1] = i[0];
	while (env_path[i[1]] && env_path[i[1]] != ':')
		i[1]++;
	plen = i[1] - i[0];
	path = (char *) malloc(sizeof(char) * (plen + 1 + flen + 1));
	if (path == NULL)
		return (NULL);
	ft_strncpy(path, env_path + i[0], plen);
	path[plen] = '\0';
	if (plen != 0 && env_path[i[1] - 1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, file_path);
	return (path);
}

int	mbn_search(char **path, char *file_path, t_minsh *minsh)
{
	char		*env_path;
	size_t		i[2];
	struct stat	st;

	env_path = ft_envlst_get(minsh->elst, "PATH");
	if (file_path == NULL || env_path == NULL)
		return (0);
	i[0] = 0;
	while (env_path[i[0]])
	{
		*path = _mbens_get_subcmd(i, file_path, env_path);
		if (*path == NULL)
			return (ft_error_return("mben_search", -1));
		if (stat(*path, &st) == 0 && S_ISREG(st.st_mode))
			return (0);
		free(*path);
		*path = NULL;
		i[0] = i[1];
		if (env_path[i[1]] == ':')
			i[0]++;
	}
	errno = ENOENT;
	return (0);
}
