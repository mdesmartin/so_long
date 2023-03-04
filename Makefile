# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:18:39 by mvogel            #+#    #+#              #
#    Updated: 2023/03/04 16:34:11 by mehdidesmar      ###   ########lyon.fr    #
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

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

MLX_LINUX_PATH = mlx_linux/

MLX_MAC_PATH = mlx_mac/

MLX_NAME = libmlx.a

UNAME := $(shell uname)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(HDR_PATH)

# ------------------------------- KERNEL ------------------------------------- #

ifeq ($(UNAME), Linux)
MLX_FLAGS =	-L $(MLX_LINUX_PATH) -l Xext -l X11 -l m
MLX = $(addprefix $(MLX_LINUX_PATH), $(MLX_NAME))
CFLAGS = -Wall -Wextra -Werror -I $(MLX_LINUX_PATH) -I $(LIBFT_PATH) -I $(HDR_PATH)
endif

ifeq ($(UNAME), Darwin)
MLX_FLAGS =	-L $(MLX_MAC_PATH) -l mlx -framework OpenGL -framework AppKit
MLX = $(addprefix $(MLX_MAC_PATH), $(MLX_NAME))
CFLAGS = -Wall -Wextra -Werror -I $(MLX_MAC_PATH) -I $(LIBFT_PATH) -I $(HDR_PATH)
endif

ifeq ($(UNAME), Linux)
all: mlx_linux
endif

ifeq ($(UNAME), Darwin)
all: mlx_mac
endif

# ------------------------------- COMPILE ------------------------------------ #

all: $(NAME)

%.o : %.c Makefile $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX_FLAGS)

$(LIBFT) : FORCE
	$(MAKE) -C $(LIBFT_PATH)

mlx_linux :
	$(MAKE) -C $(MLX_LINUX_PATH)

mlx_mac :
	$(MAKE) -C $(MLX_MAC_PATH)

FORCE :

# ------------------------------- CLEAN -------------------------------------- #

ifeq ($(UNAME), Linux)
clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_LINUX_PATH) clean
	$(RM) $(OBJ)
endif

ifeq ($(UNAME), Darwin)
clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_MAC_PATH) clean
	$(RM) $(OBJ)
endif

ifeq ($(UNAME), Linux)
fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_LINUX_PATH) clean
	$(RM) $(NAME)
endif

ifeq ($(UNAME), Darwin)
fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_MAC_PATH) clean
	$(RM) $(NAME)
endif

re : fclean
	$(MAKE) all

.PHONY: all libft mlx_linux mlx_mac clean fclean re FORCE
 