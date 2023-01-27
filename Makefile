# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesmartin <mdesmartin@student.42lyon.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:18:39 by mvogel            #+#    #+#              #
#    Updated: 2023/01/27 13:36:34 by mdesmartin       ###   ########lyon.fr    #
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

FT_PRINTF_PATH = ft_printf/

FT_PRINTF_NAME = ft_printf.a

FT_PRINTF = $(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_NAME))

all: $(NAME)

lib :
	make -C $(LIBFT_PATH)

ft_printf :
	make -C $(FT_PRINF_PATH)

$(NAME): $(OBJ) lib ft_printf
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) /usr/include -Imlx_linux -O3 -o $@ -c $<

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_LIBFT_PATH)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re libft ft_printf
