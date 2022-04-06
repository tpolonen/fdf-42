# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/04/06 14:34:04 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
HEADER_DIR 		:= include/
LIBHEADER_DIR	:= libft/include/
LIB_DIR			:= libft/
SRC_DIR 		:= src
OBJ_DIR 		:= obj

BIN := fdf
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 

CC 			:= gcc
CPPFLAGS 	:= -I$(LIBHEADER_DIR) -I$(HEADER_DIR)
CFLAGS 		:= -Wall -Wextra -Werror
LDFLAGS 	:= -L$(LIB_DIR)
LDLIBS 		:= -lft -lmlx -lm -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: lib $(BIN)

lib:
	make -C $(LIB_DIR)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@/bin/rm -frv $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean
	/bin/rm -f $(BIN)

re: fclean all
