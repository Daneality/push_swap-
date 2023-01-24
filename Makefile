# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:10:07 by dsas              #+#    #+#              #
#    Updated: 2023/01/24 13:54:34 by dsas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG = -fsanitize=address
LEAKS = leaks -atExit -- ./push-swap

# Libraries
LIBFTPRINTF_A = libft/libft.a

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFTPRINTF = libft

# Source and object files
SRCS =	push_swap.c \
		input_checking/get_input.c \
		utils/node_utils.c \
		utils/node_find.c \
		utils/key_find.c \
		operations/push.c \
		operations/revrotate.c \
		operations/rotate.c \
		operations/swap.c \
		sorting/sort_big.c \
		sorting/sort_small.c \
		sorting/sort_big2.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)
#$(DEBUG)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTPRINTF) bonus
	mv $(LIBFTPRINTF_A) libft.a
	$(CC) $(CFLAGS) $(OBJ) -L. -lft -o $(NAME)
	mv $(OBJ) $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) clean -C $(LIBFTPRINTF)

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
