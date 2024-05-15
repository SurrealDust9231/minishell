# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/05/15 10:25:34 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -D MINISHELL_ROOT_DIR="\"$(ROOT_DIR)/builtins/bin\""
AR=ar
ARFLAGS=rcs

NAME=libminback.a

INC=-Iincludes

_EOBJS=mb_executor_simple_cmd.o \
	mb_executor_pipe.o mb_executor_execute_node.o mb_executor_redirection.o
EOBJS=$(_EOBJS:%=executor/%)

_BOBJS=mb_builtin_search.o mb_builtin_cmd.o mb_builtin_cmd_cd.o \
	mb_builtin_cmd_exit.o
BOBJS=$(_BOBJS:%=builtin/%)

_NOBJS=mb_nbuiltin_search.o mb_nbuiltin_cmd.o
NOBJS=$(_NOBJS:%=nbuiltin/%)

_LIBS_INC=libft libftast libftend
LIBS_INC=$(_LIBS_INC:%=-I../libs/%)

all: $(NAME)

re: fclean all

$(NAME): $(EOBJS) $(BOBJS) $(NOBJS)
	$(AR) $(ARFLAGS) $@ $(EOBJS) $(BOBJS) $(NOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC) $(LIBS_INC)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(EOBJS) $(BOBJS) $(NOBJS)

.PHONY: all re fclean clean $(NAME)
