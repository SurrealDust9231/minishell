/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:04:06 by saguayo-          #+#    #+#             */
/*   Updated: 2024/04/30 16:24:54 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(char **array)
{
	int	count;

	count = 0;
	while (array && *array++)
		count++;
	return (count);
}
// UTILS FINAL

// COMMAN'S START
// EXPAND THE $
char *expand_variables(char *token)
{
	int i = 0;
	int result_idx = 0, in_single_quote = 0, in_double_quote = 0;
	char *result = malloc(4096);

	if (!result)
		return (NULL);
	while (token[i])
	{
		if (token[i] == '\'' && !in_double_quote)
		{
			in_single_quote = !in_single_quote;
			result[result_idx++] = token[i];
			i++;
			continue;
		}
		if (token[i] == '\"' && !in_single_quote)
		{
			in_double_quote = !in_double_quote;
			result[result_idx++] = token[i];
			i++;
			continue;
		}
		if (token[i] == '$' && !in_single_quote && (in_double_quote || !ft_isspace(token[i + 1]))) {
			char var_name[256];
			int var_idx = 0;
			i++;
			while (ft_isalnum(token[i]) || token[i] == '_')
				var_name[var_idx++] = token[i++];
			var_name[var_idx] = '\0';
			i--;
			char *var_value = getenv(var_name);
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
	return result;
}

// PWD
void	execute_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd() error");
}

// ECHO && ECHO -N
void execute_echo(char **args)
{
	int i = 1;
	int n_flag = 0;

	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n_flag = 1;
		i = 2;
	}
	while (args[i])
	{
		if ((args[i][0] == '\"' && args[i][strlen(args[i]) - 1] == '\"') ||
			(args[i][0] == '\'' && args[i][strlen(args[i]) - 1] == '\''))
		{
			args[i][strlen(args[i]) - 1] = '\0';
			printf("%s", args[i] + 1);
		}
		else
			printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
}
// CD
void execute_cd(char **args)
{
    if (count_args(args) != 2)
	{
        printf("cd: wrong number of arguments\n");
        return;
    }
    if (chdir(args[1]) != 0)
	{
        perror("cd");
    }
}

int main(void)
{
	char *line;
	char **av;
	t_astree *ast;
	int i;

	while (1)
	{
		line = readline("WRITE YOUR COMMAND: ");
		if (line == NULL)
			break ;
		add_history(line);
		printf("test\n");
		av = custom_split(line);
		if (!av)
		{
			printf("test\n");
			free(line);
			continue ;
		}
		printf("The line is: %s\n", line);
		printf("Comand and args:\n");
		i = 0;
		while (av[i] != NULL)
			printf("%s\n", av[i++]);
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		i = 0;
		while (av[i] != NULL)
		{
			char *expanded = expand_variables(av[i]);
			free(av[i]);
			av[i] = expanded;
			i++;
		}
		int index = 0;
		ast = parseCommands(av, &index);
		if (ast)
		{

			mbe_execute_node(ast);
			// freeAST(ast);
		}
		free(av);
		free(line);
	}
	return 0;
}

