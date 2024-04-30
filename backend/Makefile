# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/30 17:53:45 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libminback.a

INC=-Iincludes

_EOBJS=mb_executor_simple_cmd.o mb_executor_search_path.o mb_executor_external_cmd.o \
	mb_executor_pipe.o mb_executor_execute_node.o mb_executor_redirection.o
EOBJS=$(_EOBJS:%=executor/%)

_BOBJS=mb_builtins_cd.o mb_builtins_echo.o mb_builtins_env.o mb_builtins_exit.o mb_builtins_export.o \
	mb_builtins_pwd.o mb_builtins_unset.o
BOBJS=$(_BOBJS:%=builtins/%)

_LIBS_INC=libft libftast libftend
LIBS_INC=$(_LIBS_INC:%=-I../libs/%)

all: $(NAME)

re: fclean all

$(NAME): $(EOBJS) $(BOBJS)
	$(AR) $(ARFLAGS) $@ $(EOBJS) $(BOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC) $(LIBS_INC)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(EOBJS) $(BOBJS)

.PHONY: all re fclean clean $(NAME)
