# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/29 18:44:09 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libminback.a

INC=-Iincludes

_EOBJS=mb_executor_simple_cmd.o mb_executor_search_path.o mb_executor_external_cmd.o
EOBJS=$(_EOBJS:%=executor/%)

_LIBS_INC=libft libftast libftend
LIBS_INC=$(_LIBS_INC:%=-I../libs/%)

all: $(NAME)

re: fclean all

$(NAME): $(EOBJS)
	$(AR) $(ARFLAGS) $@ $(EOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC) $(LIBS_INC)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(EOBJS)

.PHONY: all re bonus fclean clean $(NAME)
