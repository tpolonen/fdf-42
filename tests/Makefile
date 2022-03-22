# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 16:14:24 by tpolonen          #+#    #+#              #
#    Updated: 2022/03/21 13:12:58 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = helloworld tutorial1 linedraw
CFLAGS = -g -Wall -Wextra
LINKS = -I/usr/include -lmlx -lXext -lX11 -lm -lz
#LINKS = -lmlx -framework OpenGL -framework AppKit

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) utils.c $< -o $@ $(LINKS)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(BIN)
