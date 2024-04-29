# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 19:57:47 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
OBJS=main.o comsplit.o

_SKOBJS=
SKOBJS=$(_SKOBJS:%=ftsigkit/%)
SK_DIR=ftsigkit

LIBFT_DIR=libs/libft
LIBFT_FLAGS=-lft -L$(LIBFT_DIR)

LIBFA_DIR=libs/libftast
LIBFA_FLAGS=-lftast -L$(LIBFA_DIR)

RL_FLAGS=-lreadline

NC_FLAGS=-lncurses

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFA_DIR)
	$(CC) -o $@ $(OBJS) $(LIBFT_FLAGS) $(LIBFA_FLAGS) $(RL_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. -I$(LIBFT_DIR) -I$(LIBFA_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFA_DIR) fclean
	rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFA_DIR) clean
	rm -f $(OBJS)
