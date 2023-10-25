# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 17:21:33 by nope              #+#    #+#              #
#    Updated: 2023/10/25 11:12:16 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I headers/


SRC_DIR_PRINTF := src
SRC_PRINTF := $(wildcard $(SRC_DIR_PRINTF)/*.c)
OBJ_PRINTF = ${SRC_PRINTF:.c=.o}



SRC_DIR_LIBFT := libft
SRC_LIBFT := $(wildcard $(SRC_DIR_LIBFT)/*.c)
OBJ_LIBFT = ${SRC_LIBFT:.c=.o}



all: $(NAME)

$(NAME): $(OBJ_PRINTF) $(OBJ_LIBFT) 
	ar rcs $(NAME) $(OBJ_PRINTF) $(OBJ_LIBFT)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_PRINTF) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

bonus:
	make all

re: fclean all