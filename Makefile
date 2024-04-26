# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/26 16:39:38 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
OBJS=main.o comsplit.o

_SKOBJS=
SKOBJS=$(_SKOBJS:%=ftsigkit/%)
SK_DIR=ftsigkit

LIBFT_DIR=libft
LIBFT_FLAGS=-lft -L$(LIBFT_DIR)

RL_FLAGS=-lreadline

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@make -C libft
	$(CC) -o $@ $(OBJS) $(LIBFT_FLAGS) $(RL_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. -I$(LIBFT_DIR)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

clean:
	@make -C libft clean
	rm -f $(OBJS)
