# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:32:26 by chang-pa          #+#    #+#              #
#    Updated: 2024/04/28 21:12:56 by chang-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs

NAME=libft.a

LIBFTOBJS=ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o \
	ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o \
	ft_memset.o ft_bzero.o ft_memchr.o ft_memcpy.o ft_memcmp.o ft_memmove.o \
	ft_strlcpy.o ft_strlcat.o ft_atoi.o ft_strnstr.o ft_strdup.o ft_calloc.o \
	ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o \
	ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
	ft_putnbr_fd.o ft_strcmp.o ft_isspace.o ft_strndup.o

all: $(NAME)

re: fclean all

$(NAME): $(LIBFTOBJS)
	$(AR) $(ARFLAGS) $@ $(LIBFTOBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(LIBFTOBJS)

.PHONY: all re bonus fclean clean $(NAME)
