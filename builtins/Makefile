# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 20:36:45 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/30 20:50:28 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CD_DIR=ftcd
ECHO_DIR=ftecho
ENV_DIR=ftenv
EXIT_DIR=ftexit
EXPORT_DIR=ftexport
PWD_DIR=ftpwd
UNSET_DIR=ftunset

all:
	@mkdir -p bin
	@make -C $(CD_DIR) all
	@make -C $(ECHO_DIR) all
	@make -C $(ENV_DIR) all
	@make -C $(EXIT_DIR) all
	@make -C $(EXPORT_DIR) all
	@make -C $(PWD_DIR) all
	@make -C $(UNSET_DIR) all

re: fclean all

fclean:
	@make -C $(CD_DIR) fclean
	@make -C $(ECHO_DIR) fclean
	@make -C $(ENV_DIR) fclean
	@make -C $(EXIT_DIR) fclean
	@make -C $(EXPORT_DIR) fclean
	@make -C $(PWD_DIR) fclean
	@make -C $(UNSET_DIR) fclean
	@rm -rf bin

clean:
	@make -C $(CD_DIR) clean
	@make -C $(ECHO_DIR) clean
	@make -C $(ENV_DIR) clean
	@make -C $(EXIT_DIR) clean
	@make -C $(EXPORT_DIR) clean
	@make -C $(PWD_DIR) clean
	@make -C $(UNSET_DIR) clean

.PHONY: all re fclean clean
