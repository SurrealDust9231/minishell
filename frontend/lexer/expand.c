/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:46:16 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/30 19:39:27 by saguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_frontend.h"

char	*expand_variables(char *token)
{
	int		i;
	int		result_idx;
	int		in_single_quote;
	int		in_double_quote;
	char	*result;
	char	*var_value;
	char	var_name[256];
	int		var_idx;

	i = 0;
	result_idx = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	result = malloc(4096);
	var_idx = 0;
	if (!result)
		return (NULL);
	while (token[i])
	{
		if (token[i] == '\'' && !in_double_quote)
		{
			in_single_quote = !in_single_quote;
			i++;
			continue ;
		}
		if (token[i] == '\"' && !in_single_quote)
		{
			in_double_quote = !in_double_quote;
			i++;
			continue ;
		}
		if (token[i] == '$' && !in_single_quote
			&& (in_double_quote || !ft_isspace(token[i + 1])))
		{
			i++;
			while (ft_isalnum(token[i]) || token[i] == '_')
				var_name[var_idx++] = token[i++];
			var_name[var_idx] = '\0';
			i--;
			var_value = getenv(var_name);
			if (var_value)
			{
				strcpy(&result[result_idx], var_value);
				result_idx += ft_strlen(var_value);
			}
		}
		else
			result[result_idx++] = token[i];
		i++;
	}
	result[result_idx] = '\0';
	return (result);
}
