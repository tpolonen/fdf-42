# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/04/07 02:56:06 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER_DIR = ./include/
TESTS_DIR = ./tests/
SRC_DIR = src
OBJ_DIR = obj

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -I$(HEADER_DIR)
ARFLAGS = rcs

NAME = libft.a

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@/bin/rm -r $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
