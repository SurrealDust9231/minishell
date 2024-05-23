# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 20:36:45 by chang-pa          #+#    #+#              #
#    Updated: 2024/05/22 19:38:12 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO_DIR=ftecho
PWD_DIR=ftpwd

all:
	@mkdir -p bin
	@make -C $(ECHO_DIR) all
	@make -C $(PWD_DIR) all

re: fclean all

fclean:
	@make -C $(ECHO_DIR) fclean
	@make -C $(PWD_DIR) fclean
	@rm -rf bin

clean:
	@make -C $(ECHO_DIR) clean
	@make -C $(PWD_DIR) clean

.PHONY: all re fclean clean
