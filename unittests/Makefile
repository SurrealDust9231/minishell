# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/26 19:31:46 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=unittests
OBJS=unittests.o

_NCOBJS=ncurses_test.o
NCOBJS=$(_NCOBJS:%=ncurses/%)

_RLOBJS=readline_test.o
RLOBJS=$(_RLOBJS:%=readline/%)

LIBFT_DIR=../libft
LIBFT_FLAGS=-lft -L$(LIBFT_DIR)

RL_FLAGS=-lreadline

NC_FLAGS=-lncurses

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(NCOBJS) $(RLOBJS)
	@make -C $(LIBFT_DIR)
	$(CC) -o $@ $(OBJS) $(NCOBJS) $(RLOBJS) $(LIBFT_FLAGS) $(RL_FLAGS) $(NC_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. -I$(LIBFT_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
