# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 20:36:45 by chang-pa          #+#    #+#              #
#    Updated: 2024/05/17 08:33:33 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO_DIR=ftecho
ENV_DIR=ftenv
EXPORT_DIR=ftexport
PWD_DIR=ftpwd
UNSET_DIR=ftunset

all:
	@mkdir -p bin
	@make -C $(ECHO_DIR) all
	@make -C $(ENV_DIR) all
	@make -C $(EXPORT_DIR) all
	@make -C $(PWD_DIR) all
	@make -C $(UNSET_DIR) all

re: fclean all

fclean:
	@make -C $(ECHO_DIR) fclean
	@make -C $(ENV_DIR) fclean
	@make -C $(EXPORT_DIR) fclean
	@make -C $(PWD_DIR) fclean
	@make -C $(UNSET_DIR) fclean
	@rm -rf bin

clean:
	@make -C $(ECHO_DIR) clean
	@make -C $(ENV_DIR) clean
	@make -C $(EXPORT_DIR) clean
	@make -C $(PWD_DIR) clean
	@make -C $(UNSET_DIR) clean

.PHONY: all re fclean clean
