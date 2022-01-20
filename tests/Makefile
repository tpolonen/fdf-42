# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 16:14:24 by tpolonen          #+#    #+#              #
#    Updated: 2022/01/20 11:33:31 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = helloworld tutorial1
CFLAGS = -g -Wall -Wextra
LINKS = -I/usr/include -lmlx -lXext -lX11 -lm -lz

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LINKS)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(BIN)
