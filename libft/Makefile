# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/03/24 12:57:19 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
ARFLAGS = rc
NAME = libft.a

FILES := ft_abs.c
FILES += ft_atoi.c
FILES += ft_bzero.c
FILES += ft_dstr.c
FILES += ft_getline.c
FILES += ft_intlen.c
FILES += ft_isalnum.c
FILES += ft_isalpha.c
FILES += ft_isascii.c
FILES += ft_isdigit.c
FILES += ft_islower.c
FILES += ft_isspace.c
FILES += ft_isprint.c
FILES += ft_isupper.c
FILES += ft_itoa.c
FILES += ft_lstadd.c
FILES += ft_lstadd_back.c
FILES += ft_lstcount.c
FILES += ft_lstdel.c
FILES += ft_lstdelone.c
FILES += ft_lstiter.c
FILES += ft_lstmap.c
FILES += ft_lstnew.c
FILES += ft_lstprint.c
FILES += ft_max.c
FILES += ft_memalloc.c
FILES += ft_memccpy.c
FILES += ft_memchr.c
FILES += ft_memrchr.c
FILES += ft_memcmp.c
FILES += ft_memcpy.c
FILES += ft_memdel.c
FILES += ft_memmove.c
FILES += ft_memset.c
FILES += ft_putchar.c
FILES += ft_putchar_fd.c
FILES += ft_putendl.c
FILES += ft_putendl_fd.c
FILES += ft_putnbr.c
FILES += ft_putnbr_fd.c
FILES += ft_putstr.c
FILES += ft_putstr_fd.c
FILES += ft_putmem.c
FILES += ft_strcat.c
FILES += ft_strchr.c
FILES += ft_strchrnul.c
FILES += ft_strclr.c
FILES += ft_strcmp.c
FILES += ft_strcpy.c
FILES += ft_strdel.c
FILES += ft_strdup.c
FILES += ft_strequ.c
FILES += ft_striter.c
FILES += ft_striteri.c
FILES += ft_strjoin.c
FILES += ft_strlcat.c
FILES += ft_strlcpy.c
FILES += ft_strlen.c
FILES += ft_strmap.c
FILES += ft_strmapi.c
FILES += ft_strncat.c
FILES += ft_strncmp.c
FILES += ft_strncpy.c
FILES += ft_strnequ.c
FILES += ft_strnew.c
FILES += ft_strnstr.c
FILES += ft_strrchr.c
FILES += ft_strsplit.c
FILES += ft_strstr.c
FILES += ft_strsub.c
FILES += ft_strtrim.c
FILES += ft_tolower.c
FILES += ft_toupper.c

SRC = $(FILES)
OBJ = $(SRC:.c=.o)
INC = ./includes/

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I$(INC) $(SRC)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
