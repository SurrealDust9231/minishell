# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:41:20 by chang-pa          #+#    #+#              #
#    Updated: 2024/05/21 19:21:47 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

AR=ar
ARFLAGS=rcs

NAME=libftenvlst.a

OBJS=ft_envlst_create.o ft_envlst_destroy.o ft_envlst_init.o ft_envlst_get.o ft_envlst_delone.o ft_envlst_push.o \
	ft_envlst_showall.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)
