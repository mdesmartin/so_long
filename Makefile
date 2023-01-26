# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:18:39 by mvogel            #+#    #+#              #
#    Updated: 2023/01/26 13:55:54 by mvogel           ###   ########lyon.fr    #
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
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -Imlx -o $@ -c $<

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
