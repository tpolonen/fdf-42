# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/05/06 16:22:11 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER_DIR = ./include/
TESTS_DIR = ./tests/
SRC_DIR = src
OBJ_DIR = obj

_SRC := ft_abs.c
_SRC += ft_atoi.c
_SRC += ft_bzero.c
_SRC += ft_calloc.c
_SRC += ft_dstr.c
_SRC += ft_getline.c
_SRC += ft_intlen.c
_SRC += ft_isalnum.c
_SRC += ft_isalpha.c
_SRC += ft_isascii.c
_SRC += ft_isdigit.c
_SRC += ft_islower.c
_SRC += ft_isprint.c
_SRC += ft_isspace.c
_SRC += ft_isupper.c
_SRC += ft_itoa.c
_SRC += ft_lstadd.c
_SRC += ft_lstadd_back.c
_SRC += ft_lstcount.c
_SRC += ft_lstdel.c
_SRC += ft_lstdelone.c
_SRC += ft_lstiter.c
_SRC += ft_lstmap.c
_SRC += ft_lstnew.c
_SRC += ft_lstprint.c
_SRC += ft_max.c
_SRC += ft_memalloc.c
_SRC += ft_memccpy.c
_SRC += ft_memchr.c
_SRC += ft_memcmp.c
_SRC += ft_memcpy.c
_SRC += ft_memdel.c
_SRC += ft_memmove.c
_SRC += ft_memrchr.c
_SRC += ft_memset.c
_SRC += ft_memset.c.orig
_SRC += ft_putchar.c
_SRC += ft_putchar_fd.c
_SRC += ft_putendl.c
_SRC += ft_putendl_fd.c
_SRC += ft_putmem.c
_SRC += ft_putnbr.c
_SRC += ft_putnbr_fd.c
_SRC += ft_putstr.c
_SRC += ft_putstr_fd.c
_SRC += ft_strcat.c
_SRC += ft_strchr.c
_SRC += ft_strchrnul.c
_SRC += ft_strclr.c
_SRC += ft_strcmp.c
_SRC += ft_strcpy.c
_SRC += ft_strdel.c
_SRC += ft_strdup.c
_SRC += ft_strequ.c
_SRC += ft_striter.c
_SRC += ft_striteri.c
_SRC += ft_strjoin.c
_SRC += ft_strlcat.c
_SRC += ft_strlcpy.c
_SRC += ft_strlen.c
_SRC += ft_strmap.c
_SRC += ft_strmapi.c
_SRC += ft_strncat.c
_SRC += ft_strncmp.c
_SRC += ft_strncpy.c
_SRC += ft_strnequ.c
_SRC += ft_strnew.c
_SRC += ft_strnstr.c
_SRC += ft_strrchr.c
_SRC += ft_strsplit.c
_SRC += ft_strstr.c
_SRC += ft_strsub.c
_SRC += ft_strtol.c
_SRC += ft_strtrim.c
_SRC += ft_tolower.c
_SRC += ft_toupper.c

DEP := $(HEADER_DIR)libft.h
DEP += $(HEADER_DIR)get_next_line.h

NAME = libft.a
SRC := $(patsubst %,$(SRC_DIR)/%,$(_SRC))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 

CC 			:= gcc
CPPFLAGS	:= -I$(HEADER_DIR)
CFLAGS 		:= -g -c -Wall -Wextra -Werror -I$(HEADER_DIR)
ARFLAGS 	:= rcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(DEP)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Libft: Compiled

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

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
