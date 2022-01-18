# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 16:14:24 by tpolonen          #+#    #+#              #
#    Updated: 2022/01/15 16:29:54 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = helloworld.c
OBJ = $(subst .c,.o,$(SRC))

CFLAGS = -Wall -Wextra
LINKS = -I/usr/include -lmlx -lXext -lX11 -lm -lz

hello: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o hello $(LINKS)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf hello

re: fclean hello
