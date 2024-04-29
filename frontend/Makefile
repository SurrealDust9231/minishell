# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 21:06:59 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libminfront.a

INC=includes

_POBJS=parseCommands.o
POBJS=$(_POBJS:%=parsing/%)

LIBFT_DIR=../libs/libft
LIBFA_DIR=../libs/libftast

all: $(NAME)

re: fclean all

$(NAME): $(POBJS)
	$(AR) $(ARFLAGS) $@ $(POBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(LIBFT_DIR) -I$(LIBFA_DIR)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(POBJS)

.PHONY: all re bonus fclean clean $(NAME)
