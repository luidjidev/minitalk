# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 14:36:04 by luisfern          #+#    #+#              #
#    Updated: 2022/10/18 15:37:18 by luisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME1 = client
NAME2 = server
PRINTF_LIB = libftprintf.a
PRINTF_DIR = ft_printf/
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

#Source Files

SRC_FILES = client server

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = client server

###

OBJF = .cache_exists

all: $(NAME1) $(NAME2)

$(NAME1):
		make -C ft_printf/
		cp ft_printf/libftprintf.a .
		$(CC) $(CFLAGS) -o client client.c libftprintf.a

$(NAME2):
		make -C ft_printf/
		cp ft_printf/libftprintf.a .
		$(CC) $(CFLAGS) -o server server.c libftprintf.a

clean: 
	rm -rf $(NAME1) $(NAME2)

fclean:
	rm -rf $(NAME1) $(NAME2) $(PRINTF_LIB)
	make fclean -C ft_printf/

re: fclean all

.PHONY: all clean fclean re