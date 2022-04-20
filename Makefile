# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/04/19 17:20:17 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
HEADER_DIR 		:= include/
LIBHEADER_DIR	:= libft/include/
LLIBHEADER_DIR	:= /usr/include/
LIB_DIR			:= libft/
SRC_DIR 		:= src
OBJ_DIR 		:= obj

BIN := fdf
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 

CC 			:= gcc
CPPFLAGS 	:= -I$(LIBHEADER_DIR) -I$(HEADER_DIR)
LCPPFLAGS	:= -I$(LLIBHEADER_DIR) -DLINUX
CFLAGS 		:= -g
LDFLAGS 	:= -L$(LIB_DIR)
LDLIBS 		:= -lft -lmlx -lm -framework OpenGL -framework AppKit
LLDLIBS		:= -lft -lmlx -lm -lz -lXext -lX11

.PHONY: all clean fclean re

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CPPFLAGS += $(LCPPFLAGS)
	LDLIBS = $(LLDLIBS)
endif

all: lib $(BIN)
	@echo $(CPPFLAGS)
	@echo $(LDLIBS)

lib:
	make -C $(LIB_DIR)
	@echo Compiled library

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@echo Compiled binary file

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@/bin/rm -fr $(OBJ_DIR)
	@echo Removed .o files

fclean: clean
	@make -C $(LIB_DIR) fclean
	@echo Fcleaned library
	/bin/rm -f $(BIN)

re: fclean all
