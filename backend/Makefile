# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 19:58:54 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libminback.a

INC=includes

_EOBJS=mb_executor_simple.o mb_executor_search_path.o
EOBJS=$(_EOBJS:%=executor/%)

LIBFT_DIR=../libs/libft
LIBFA_DIR=../libs/libftast

all: $(NAME)

re: fclean all

$(NAME): $(EOBJS)
	$(AR) $(ARFLAGS) $@ $(EOBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(LIBFT_DIR) -I$(LIBFA_DIR)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(EOBJS)

.PHONY: all re bonus fclean clean $(NAME)
