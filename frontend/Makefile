# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/30 18:51:15 by saguayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libminfront.a

INC=includes

_POBJS=parse_commands.o
POBJS=$(_POBJS:%=parsing/%)

_LOBJS=split.o expand.o
LOBJS=$(_LOBJS:%=lexer/%)

LIBFT_DIR=../libs/libft
LIBFA_DIR=../libs/libftast

all: $(NAME)

re: fclean all

$(NAME): $(POBJS) $(LOBJS)
	$(AR) $(ARFLAGS) $@ $(POBJS) $(LOBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(LIBFT_DIR) -I$(LIBFA_DIR)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(POBJS) $(LOBJS)

.PHONY: all re bonus fclean clean $(NAME)
