/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_executor_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:48:20 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/28 21:46:22 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_backend.h"

static int	_mbes_execv(char **argv)
{
	char *path;

	if (strchr(argv[0], '/'))
		execve(argv[0], argv, NULL);
	else
	{
		path = mbe_search_path(argv[0]);
		if(!path)
			return (0);
		execve(path, argv, NULL);
		free(path);
	}
	return (0);
}

static void	_mbes_free_argv(int argc, char **argv)
{
	if(!argc)
		return ;
	while(argc--)
		free(argv[argc]);
}

int mbe_simple_cmd(t_astree *node)
{
	// struct node_s *child;

    // if(!node)
    //     return 0;
    //  = node->first_child;
    // if(!child)
    // {
    //     return 0;
    // }

    // int argc = 0;
    // long max_args = 255;
    // char *argv[max_args+1];/* keep 1 for the terminating NULL arg */
    // char *str;

    // while(child)
    // {
    //     str = child->val.str;
    //     argv[argc] = malloc(strlen(str)+1);

	// if(!argv[argc])
    //     {
    //         free_argv(argc, argv);
    //         return 0;
    //     }

	// strcpy(argv[argc], str);
    //     if(++argc >= max_args)
    //     {
    //         break;
    //     }
    //     child = child->next_sibling;
    // }
    // argv[argc] = NULL;
    // pid_t child_pid = 0;
    // if((child_pid = fork()) == 0)
    // {
    //     do_exec_cmd(argc, argv);
    //     fprintf(stderr, "error: failed to execute command: %s\n",
    //             strerror(errno));
    //     if(errno == ENOEXEC)
    //     {
    //         exit(126);
    //     }
    //     else if(errno == ENOENT)
    //     {
    //         exit(127);
    //     }
    //     else
    //     {
    //         exit(EXIT_FAILURE);
    //     }
    // }
    // else if(child_pid < 0)
    // {
    //     fprintf(stderr, "error: failed to fork command: %s\n",
    //             strerror(errno));
    //     return 0;
    // }
    // int status = 0;
    // waitpid(child_pid, &status, 0);
    // free_argv(argc, argv);

    // return 1;
	_mbes_execv(node->data);
	_mbes_free_argv(3, node->data);
	return (0);
}
