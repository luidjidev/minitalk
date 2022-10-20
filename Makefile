# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 14:36:04 by luisfern          #+#    #+#              #
#    Updated: 2022/10/20 15:27:13 by luisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

FILE_S = server.c
FILE_C = client.c

EXE_S = server
EXE_C = client

PRINTF = ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)

$(CLIENT): $(PRINTF)
		@ $(CC) $(CFLAGS) $(FILE_C) $(PRINTF) -o $(CLIENT)
		@ echo client ready.

$(SERVER): $(PRINTF)
		@ $(CC) $(CFLAGS) $(FILE_S) $(PRINTF) -o $(SERVER)
		@ echo server ready.

$(PRINTF): 
		@ make -C ft_printf/
		@ cp ft_printf/libftprintf.a .

clean: 
		@ $(RM) $(CLIENT) $(SERVER)
		@ echo client n server deleted.

fclean: clean
		@ $(RM) libftprintf.a
		@ echo all deleted.
		
re: fclean all
		@ echo recompiling