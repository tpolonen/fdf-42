# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 16:14:24 by tpolonen          #+#    #+#              #
#    Updated: 2022/04/04 13:13:27 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = helloworld tutorial1 linedraw 2dcoords
CFLAGS = -g -Wall -Wextra
LINKS = -I/usr/include -I../libft/includes -L../libft/ -lft -lmlx -lXext -lX11 -lm -lz
#LINKS = -lmlx -framework OpenGL -framework AppKit

all: $(BIN)

lib:
	make -C ../libft/

%: %.c lib
	$(CC) $(CFLAGS) utils.c events.c $< -o $@.out $(LINKS)

clean:
	/bin/rm -rf *.o

fclean: clean
	make -C ../libft/ fclean 
	/bin/rm -rf $(BIN)
