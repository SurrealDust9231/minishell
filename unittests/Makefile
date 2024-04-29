# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/29 14:17:47 by chang-pa         ###   ########.fr        #
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

_FAOBJS=ftast_vis_test.o
FAOBJS=$(_FAOBJS:%=ftast/%)

LIBFT_DIR=../libs/libft
LIBFT_FLAGS=-lft -L$(LIBFT_DIR)

LIBFA_DIR=../libs/libftast
LIBFA_FLAGS=-lftast -L$(LIBFA_DIR)

RL_FLAGS=-lreadline

NC_FLAGS=-lncurses

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(NCOBJS) $(RLOBJS) $(FAOBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFA_DIR)
	$(CC) -o $@ $(OBJS) $(NCOBJS) $(RLOBJS) $(FAOBJS) $(LIBFT_FLAGS) $(LIBFA_FLAGS) $(RL_FLAGS) $(NC_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. -I$(LIBFT_DIR) -I$(LIBFA_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFA_DIR) fclean
	rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFA_DIR) clean
	rm -f $(OBJS) $(NCOBJS) $(RLOBJS) $(FAOBJS)
