# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 20:21:30 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/30 20:51:24 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=unset

OBJS=ft_unset.o

LIBS_DIR=../../libs
LIBFT_DIR=$(LIBS_DIR)/libft
LIBFA_DIR=$(LIBS_DIR)/libftast
LIBFEND_DIR=$(LIBS_DIR)/libftend
LIBS_FLAGS=-lft -L$(LIBFT_DIR) -lftast -L$(LIBFA_DIR) -lftend -L$(LIBFEND_DIR)
LIBS_INC=-I$(LIBFT_DIR) -I$(LIBFA_DIR) -I$(LIBFEND_DIR)

BIN_DIR=../bin

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(OBJS) $(LIBS_FLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I. $(LIBS_INC)

fclean: clean
	@rm -f $(BIN_DIR)/$(NAME)

clean:
	@rm -f $(OBJS)

.PHONY: all re $(NAME) fclean clean
