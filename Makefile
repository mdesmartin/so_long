# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:18:39 by mvogel            #+#    #+#              #
#    Updated: 2023/03/05 15:34:50 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ---------------------------------- #

NAME = so_long

HDR_PATH = include/

HDR_LST = so_long.h \
			prototype.h \
			structure.h

HDR = $(addprefix $(HDR_PATH), $(HDR_LST))

SRC_PATH = src/

SRC_LST = main.c \
		parsing.c \
		check_error.c \
		check_map.c \
		init.c \
		display.c \
		exit.c \

SRC = $(addprefix $(SRC_PATH), $(SRC_LST))

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(MLX_LINUX_PATH) -I $(HDR_PATH)

# ------------------------------- LIBFT -------------------------------------- #

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

# ------------------------------- MLX ---------------------------------------- #

MLX_LINUX_PATH = mlx_linux/

MLX_NAME = libmlx.a

MLX_FLAGS =	-L $(MLX_LINUX_PATH) -l Xext -l X11 -l m

MLX = $(addprefix $(MLX_LINUX_PATH), $(MLX_NAME))

# ------------------------------- COMPILE ------------------------------------ #

all: $(NAME)

%.o : %.c Makefile $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):  $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX_FLAGS)

$(LIBFT) : FORCE
	$(MAKE) -C $(LIBFT_PATH)

$(MLX) : FORCE
	$(MAKE) -C $(MLX_LINUX_PATH)

FORCE :

# ------------------------------- CLEAN -------------------------------------- #

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_LINUX_PATH) clean
	$(RM) $(OBJ)

fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_LINUX_PATH) clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all libft mlx_linux clean fclean re FORCE
 