# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 00:28:11 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/29 18:01:38 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=unittests
OBJS=unittests.o

_FAOBJS=ftast_vis_test.o
FAOBJS=$(_FAOBJS:%=ftast/%)

_EXOBJS=mbe_simple_cmd_test.o
_NCOBJS=ncurses_test.o
_RLOBJS=readline_test.o
BEOBJS=$(_EXOBJS:%=executor/%) $(_RLOBJS:%=readline/%) $(_NCOBJS:%=ncurses/%)

LIBS_DIR=../libs
LIBFT_DIR=$(LIBS_DIR)/libft
LIBFEND_DIR=$(LIBS_DIR)/libftend
LIBFA_DIR=$(LIBS_DIR)/libftast
LIBS_FLAGS=-lft -L$(LIBFT_DIR) -lftend -L$(LIBFEND_DIR) -lftast -L$(LIBFA_DIR)
LIBS_INC=-I$(LIBFT_DIR) -I$(LIBFEND_DIR) -I$(LIBFA_DIR)

BE_DIR=../backend
BE_FLAGS=-lminback -L$(BE_DIR) -lreadline -lncurses
BE_INC=-I$(BE_DIR)/includes

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(FAOBJS) $(BEOBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFEND_DIR)
	@make -C $(LIBFA_DIR)
	@make -C $(BE_DIR)
	$(CC) -o $@ $(OBJS) $(FAOBJS) $(BEOBJS) $(LIBS_FLAGS) $(BE_FLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< -I. $(LIBS_INC) $(BE_INC)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFA_DIR) fclean
	@make -C $(LIBFEND_DIR) fclean
	@make -C $(BE_DIR) fclean
	rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFA_DIR) clean
	@make -C $(LIBFEND_DIR) clean
	@make -C $(BE_DIR) clean
	rm -f $(OBJS) $(FAOBJS) $(BEOBJS)
