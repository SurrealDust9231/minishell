# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:41:20 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 21:43:52 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

AR=ar
ARFLAGS=rcs

NAME=libftast.a

OBJS=ft_ast_create.o ft_ast_destroy.o ft_ast_init.o ft_ast_vis.o ft_ast_data_destroy.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)
