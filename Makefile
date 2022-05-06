# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/05/06 19:39:30 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
HEADER_DIR 		:= include/
LIBHEADER_DIR	:= libft/include/
LLIBHEADER_DIR	:= /usr/include/
LIB_DIR			:= libft/
SRC_DIR 		:= src
OBJ_DIR 		:= obj

_SRC := dintarr.c
_SRC += draw.c
_SRC += events.c
_SRC += fileread.c
_SRC += main.c
_SRC += map.c
_SRC += projections.c

DEP := $(HEADER_DIR)fdf.h
DEP += $(HEADER_DIR)dintarr.h

BIN := fdf
SRC := $(patsubst %,$(SRC_DIR)/%,$(_SRC))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 

CC 			:= gcc
CPPFLAGS 	:= -I$(LIBHEADER_DIR) -I$(HEADER_DIR)
LCPPFLAGS	:= -I$(LLIBHEADER_DIR) -DLINUX
CFLAGS 		:= -c -Wall -Wextra -Werror
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

lib:
	@make -C $(LIB_DIR)
	@echo Compiled library

$(BIN): $(OBJ) $(DEP)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(BIN)
	@echo Compiled binary file

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@/bin/rm -fr $(OBJ_DIR)
	@echo Removed .o files
	@make -C $(LIB_DIR) clean

fclean: clean
	@make -C $(LIB_DIR) fclean
	@echo Fcleaned library
	@/bin/rm -f $(BIN)
	@echo Removed binary

re: fclean all
	@echo Rebuilt
