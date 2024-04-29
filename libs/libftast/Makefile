# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:52:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 19:55:08 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

AR=ar
ARFLAGS=rcs

NAME=libftast.a

OBJS=

all: $(NAME)

$(NAME):
	$(AR) $(ARFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)
