# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:18:39 by mvogel            #+#    #+#              #
#    Updated: 2023/02/07 14:16:52 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = so_long

HEADER = so_long.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

all: libft
	make $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -o $@ -c $<

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re libft
