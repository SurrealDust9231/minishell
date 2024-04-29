# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/29 18:06:23 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
OBJS=main.o comsplit.o execute.o

_SKOBJS=
SKOBJS=$(_SKOBJS:%=ftsigkit/%)
SK_DIR=ftsigkit

LIBS_DIR=libs
LIBFT_DIR=$(LIBS_DIR)/libft
LIBFA_DIR=$(LIBS_DIR)/libftast
LIBFEND_DIR=$(LIBS_DIR)/libftend
LIBS_FLAGS=-lft -L$(LIBFT_DIR) -lftast -L$(LIBFA_DIR) -lftend -L$(LIBFEND_DIR)
LIBS_INC=-I$(LIBFT_DIR) -I$(LIBFA_DIR) -I$(LIBFEND_DIR)

FE_DIR=frontend
FE_FLAGS=-lminfront -L$(FE_DIR)
FE_INC=-I$(FE_DIR)/includes

BE_DIR=backend
BE_FLAGS=-lminback -L$(BE_DIR)
BE_INC=-I$(BE_DIR)/includes

RL_FLAGS=-lreadline

NC_FLAGS=-lncurses

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFA_DIR)
	@make -C $(LIBFEND_DIR)
	@make -C $(FE_DIR)
	@make -C $(BE_DIR)
	$(CC) -o $@ $(OBJS) $(FE_FLAGS) $(BE_FLAGS) $(LIBS_FLAGS) $(RL_FLAGS) $(NC_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. $(FE_INC) $(BE_INC) $(LIBS_INC)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFA_DIR) fclean
	@make -C $(LIBFEND_DIR) fclean
	@make -C $(FE_DIR) fclean
	@make -C $(BE_DIR) fclean
	@rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFA_DIR) clean
	@make -C $(LIBFEND_DIR) clean
	@make -C $(FE_DIR) clean
	@make -C $(BE_DIR) clean
	@rm -f $(OBJS)

.PHONY: all re $(NAME) fclean clean
