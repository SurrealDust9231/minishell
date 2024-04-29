/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_search_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:53:01 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 17:37:53 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_backend.h"

static char	*_mbesp_get_subcmd(size_t i[2], char *file_path, char *env_path)
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

char	*mbe_search_path(char *file_path)
{
	char		*env_path;
	char		*path;
	size_t		i[2];
	struct stat	st;

	env_path = getenv("PATH");
	if (file_path == NULL || env_path == NULL)
		return (NULL);
	i[0] = 0;
	while (env_path[i[0]])
	{
		path = _mbesp_get_subcmd(i, file_path, env_path);
		if (path == NULL)
			return (NULL);
		if (stat(path, &st) == 0 && S_ISREG(st.st_mode))
			return (path);
		free(path);
		i[0] = i[1];
		if (env_path[i[1]] == ':')
			i[0]++;
	}
	errno = ENOENT;
	return (NULL);
}
