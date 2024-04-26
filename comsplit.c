/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:38:43 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/26 16:38:44 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **custom_split(char *str)
{
	int in_single_quote = 0, in_double_quote = 0;
	char **result = (char **) malloc(128 * sizeof(char *));
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
