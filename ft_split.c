/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:36:56 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/26 15:15:11 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!(dest))
		return (0);
	while (*s1)
		dest[i++] = *s1++;
	dest[i] = '\0';
	return (dest);
}

char **custom_split(char *str)
{
	int in_single_quote = 0, in_double_quote = 0;
	char **result = malloc(128 * sizeof(char *));
	char token[1024];
	int token_index = 0;
	int result_index = 0;
	int i = 0;

	if (!result)
		return NULL;
	while (str[i])
	{
		char current = str[i];
		if (current == '\'' && !in_double_quote)
		{
			in_single_quote = !in_single_quote;
			token[token_index++] = current;
			i++;
			continue;
		}
		if (current == '\"' && !in_single_quote)
		{
			in_double_quote = !in_double_quote;
			token[token_index++] = current;
			i++;
			continue;
		}
		if (current == ' ' && !in_single_quote && !in_double_quote)
		{
			if (token_index != 0)
			{
				token[token_index] = '\0';
				result[result_index++] = ft_strdup(token);
				token_index = 0;
			}
		}
		else
			token[token_index++] = current;
		i++;
	}
	if (token_index != 0)
	{
		token[token_index] = '\0';
		result[result_index++] = ft_strdup(token);
	}
	result[result_index] = NULL;
	if (in_single_quote || in_double_quote)
	{
		printf("Syntax error: unmatched quote\n");
		int j = 0;
		while (j < result_index)
			free(result[j++]);
		free(result);
		return (NULL);
	}
	return (result);
}
