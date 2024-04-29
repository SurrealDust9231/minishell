# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 21:17:52 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
OBJS=main.o comsplit.o execute.o ast.o

_SKOBJS=
SKOBJS=$(_SKOBJS:%=ftsigkit/%)
SK_DIR=ftsigkit

LIBFT_DIR=libs/libft
LIBFT_FLAGS=-lft -L$(LIBFT_DIR)

LIBFA_DIR=libs/libftast
LIBFA_FLAGS=-lftast -L$(LIBFA_DIR)

FE_DIR=frontend
FE_FLAGS=-lfminfront -L$(FE_DIR)

BE_DIR=backend
BE_FLAGS=-lfminback -L$(BE_DIR)

RL_FLAGS=-lreadline

NC_FLAGS=-lncurses

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFA_DIR)
	@make -C $(FE_DIR)
	@make -C $(BE_DIR)
	$(CC) -o $@ $(OBJS) $(FE_FLAGS) $(BE_FLAGS) $(LIBFT_FLAGS) $(LIBFA_FLAGS) $(RL_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. -I$(FE_DIR) -I$(BE_DIR) -I$(LIBFT_DIR) -I$(LIBFA_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFA_DIR) fclean
	@make -C $(FE_DIR) fclean
	@make -C $(BE_DIR) fclean
	rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFA_DIR) clean
	@make -C $(FE_DIR) clean
	@make -C $(BE_DIR) clean
	rm -f $(OBJS)
