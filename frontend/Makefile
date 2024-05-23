# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguayo- <saguayo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/05/22 21:41:09 by saguayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libminfront.a

INC=includes

_POBJS=parse_commands.o parse_utils.o
POBJS=$(_POBJS:%=parsing/%)

_LOBJS=split.o split_utils.o expand.o expand_utils.o
LOBJS=$(_LOBJS:%=lexer/%)

_LIBS_INC=libft libftast libftend libftenvlst
LIBS_INC=$(_LIBS_INC:%=-I../libs/%)

all: $(NAME)

re: fclean all

$(NAME): $(POBJS) $(LOBJS)
	$(AR) $(ARFLAGS) $@ $(POBJS) $(LOBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) $(LIBS_INC)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(POBJS) $(LOBJS)

.PHONY: all re bonus fclean clean $(NAME)
