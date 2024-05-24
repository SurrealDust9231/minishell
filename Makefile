# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/05/24 12:36:10 by saguayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
OBJS=main.o signal/handle_cmd_signals.o signal/handle_global_signals.o

BTIN_DIR=builtins

LIBS_DIR=libs
LIBFT_DIR=$(LIBS_DIR)/libft
LIBFA_DIR=$(LIBS_DIR)/libftast
LIBFEND_DIR=$(LIBS_DIR)/libftend
LIBELST_DIR=$(LIBS_DIR)/libftenvlst
LIBS_FLAGS=-lft -L$(LIBFT_DIR) -lftast -L$(LIBFA_DIR) -lftend -L$(LIBFEND_DIR) -lftenvlst -L$(LIBELST_DIR)
LIBS_INC=-I$(LIBFT_DIR) -I$(LIBFA_DIR) -I$(LIBFEND_DIR) -I$(LIBELST_DIR)

FE_DIR=frontend
FE_FLAGS=-lminfront -L$(FE_DIR)
FE_INC=-I$(FE_DIR)/includes

BE_DIR=backend
BE_FLAGS=-lminback -L$(BE_DIR)
BE_INC=-I$(BE_DIR)/includes

# RL_FLAGS= -lreadline
RL_FLAGS=-Lreadline readline/libhistory.a \
readline/libreadline.a

NC_FLAGS=-lncurses

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFA_DIR)
	@make -C $(LIBFEND_DIR)
	@make -C $(LIBELST_DIR)
	@make -C $(FE_DIR)
	@ROOT_DIR=$(ROOT_DIR) make -C $(BE_DIR)
	@make -C $(BTIN_DIR)
	$(CC) -o $@ $(OBJS) $(FE_FLAGS) $(BE_FLAGS) $(LIBS_FLAGS) $(RL_FLAGS) $(NC_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. $(FE_INC) $(BE_INC) $(LIBS_INC)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFA_DIR) fclean
	@make -C $(LIBFEND_DIR) fclean
	@make -C $(LIBELST_DIR) fclean
	@make -C $(FE_DIR) fclean
	@make -C $(BE_DIR) fclean
	@make -C $(BTIN_DIR) fclean
	@rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFA_DIR) clean
	@make -C $(LIBFEND_DIR) clean
	@make -C $(LIBELST_DIR) clean
	@make -C $(FE_DIR) clean
	@make -C $(BE_DIR) clean
	@make -C $(BTIN_DIR) clean
	@rm -f $(OBJS)

rootd:
	@echo $(ROOT_DIR)

.PHONY: all re $(NAME) fclean clean rootd
