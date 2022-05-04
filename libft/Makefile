# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/05/04 13:15:19 by teppo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER_DIR = ./include/
TESTS_DIR = ./tests/
SRC_DIR = src
OBJ_DIR = obj

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror -I$(HEADER_DIR)
ARFLAGS = rcs

NAME = libft.a

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Libft: Compiled

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo Libft: .o files removed

fclean: clean
	@/bin/rm -f $(NAME)
	@echo Libft: .a file removed

re: fclean all
	@echo Libft: Rebuilt

.PHONY: all clean fclean re
