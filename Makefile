# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 17:21:33 by nope              #+#    #+#              #
#    Updated: 2023/10/25 11:23:57 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT = libft/libft.a


SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ = ${SRC:.c=.o}


all: $(NAME)

$(NAME): $(OBJ)
	cd libft/ && make all bonus && cd ..
	ar rcs $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

bonus:
	make all

re: fclean all