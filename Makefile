# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 17:21:33 by nope              #+#    #+#              #
#    Updated: 2023/10/23 14:43:47 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT = lib/libft.a
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

bonus:
	make all

re: fclean all