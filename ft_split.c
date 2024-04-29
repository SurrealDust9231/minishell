/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:38:43 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/28 20:31:28 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char **custom_split(char *str)
// {
// 	int in_single_quote = 0, in_double_quote = 0;
// 	char **result = (char **) malloc(128 * sizeof(char *));
// 	char token[1024];
// 	int token_index = 0;
// 	int result_index = 0;
// 	int i = 0;

// 	if (!result)
// 		return NULL;
// 	while (str[i])
// 	{
// 		char current = str[i];
// 		if (current == '\'' && !in_double_quote)
// 		{
// 			in_single_quote = !in_single_quote;
// 			token[token_index++] = current;
// 			i++;
// 			continue;
// 		}
// 		if (current == '\"' && !in_single_quote)
// 		{
// 			in_double_quote = !in_double_quote;
// 			token[token_index++] = current;
// 			i++;
// 			continue;
// 		}
// 		if (current == ' ' && !in_single_quote && !in_double_quote)
// 		{
// 			if (token_index != 0)
// 			{
// 				token[token_index] = '\0';
// 				result[result_index++] = ft_strdup(token);
// 				token_index = 0;
// 			}
// 		}
// 		else
// 			token[token_index++] = current;
// 		i++;
// 	}
// 	if (token_index != 0)
// 	{
// 		token[token_index] = '\0';
// 		result[result_index++] = ft_strdup(token);
// 	}
// 	result[result_index] = NULL;
// 	if (in_single_quote || in_double_quote)
// 	{
// 		printf("Syntax error: unmatched quote\n");
// 		int j = 0;
// 		while (j < result_index)
// 			free(result[j++]);
// 		free(result);
// 		return (NULL);
// 	}
// 	return (result);
// }

char **custom_split(char *str)
{
    int in_single_quote = 0, in_double_quote = 0;
    char **result = (char **)malloc(128 * sizeof(char *));
    char token[1024];
    int token_index = 0;
    int result_index = 0;
    int i = 0;

    if (!result)
		return (NULL);
    while (str[i])
	{
        char current = str[i];
        // Handle single quotes
        if (current == '\'' && !in_double_quote)
		{
            in_single_quote = !in_single_quote;
            token[token_index++] = current;  // Include the quote for further processing
            i++;
            continue;
        }
        // Handle double quotes
        if (current == '\"' && !in_single_quote)
		{
            in_double_quote = !in_double_quote;
            token[token_index++] = current;  // Include the quote for further processing
            i++;
            continue;
        }
        // Handle operators and spaces
        if (!in_single_quote && !in_double_quote)
		{
            if (ft_isspace(current))
			{
                if (token_index != 0)
				{
                    token[token_index] = '\0';
                    result[result_index++] = ft_strdup(token);
                    token_index = 0;
                }
                i++;
                while (ft_isspace(str[i]))
					i++;  // Skip subsequent spaces
                continue ;
            }
            // Check for operators and handle accordingly
            if (current == '>' || current == '<' || current == '|')
			{
                if (token_index != 0)
				{
                    token[token_index] = '\0';
                    result[result_index++] = ft_strdup(token);
                    token_index = 0;
                }
                // Handle double characters for ">>" and "<<"
                if ((current == '>' || current == '<') && str[i + 1] == current)
				{
                    result[result_index++] = ft_strndup(str + i, 2); // Save ">>" or "<<"
                    i += 2;
                }
				else
				{
                    result[result_index++] = ft_strndup(str + i, 1); // Save ">", "<", or "|"
                    i++;
                }
                continue;
            }
        }
        // Add current character to token
        token[token_index++] = current;
        i++;
    }
    if (token_index != 0)
	{
        token[token_index] = '\0';
        result[result_index++] = strdup(token);
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
