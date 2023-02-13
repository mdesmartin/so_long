/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/13 11:16:21 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int i = -1;

	while (map[++i])
		ft_printf("%s\n", map[i]);
	ft_printf("\n");
}

void	init_img(t_sl *sl)
{
	sl->mlx = mlx_init();

	sl->img_width = 64;
	sl->img_height = 64;
	
	sl->mlx_win = mlx_new_window(sl->mlx, sl->img_width * sl->x, sl->img_height * sl->y, "Hello world!");

	sl->path_wall = "img/wall.xpm";
	sl->path_floor = "img/floor.xpm";
	sl->path_collectible = "img/collectible.xpm";
	sl->path_exit = "img/exit.xpm";
	sl->path_position = "img/position.xpm";

	sl->wall = mlx_xpm_file_to_image(sl->mlx, sl->path_wall, &sl->img_width, &sl->img_height);
	sl->floor = mlx_xpm_file_to_image(sl->mlx, sl->path_floor, &sl->img_width, &sl->img_height);
	sl->collectible = mlx_xpm_file_to_image(sl->mlx, sl->path_collectible, &sl->img_width, &sl->img_height);
	sl->exit = mlx_xpm_file_to_image(sl->mlx, sl->path_exit, &sl->img_width, &sl->img_height);
	sl->position = mlx_xpm_file_to_image(sl->mlx, sl->path_position, &sl->img_width, &sl->img_height);
}

void	init_map(t_sl *sl)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == '0')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->floor, x * sl->img_width, y * sl->img_width);
			else if (sl->map[y][x] == '1')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->wall, x * sl->img_width, y * sl->img_width);
			else if (sl->map[y][x] == 'P')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->position, x * sl->img_width, y * sl->img_width);
			else if (sl->map[y][x] == 'E')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->exit, x * sl->img_width, y * sl->img_width);
			else if (sl->map[y][x] == 'C')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->collectible, x * sl->img_width, y * sl->img_width);
			x++;
		}
		y++;
	}
}

int	ft_key(int key, t_sl *sl)
{
	ft_printf("%d : %d : %d\n", key, sl->p_x, sl->x);
	(void) sl;
	mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->floor, sl->p_x * sl->img_width, sl->p_y * sl->img_width);
	if (key == 100 && sl->map[sl->p_y][sl->p_x + 1] != '1')//d
		sl->p_x += 1;
	if (key == 97 && sl->map[sl->p_y][sl->p_x - 1] != '1')//g
		sl->p_x -= 1;
	if (key == 115 && sl->map[sl->p_y + 1][sl->p_x] != '1')
		sl->p_y += 1;
	if (key == 119 && sl->map[sl->p_y - 1][sl->p_x] != '1')
		sl->p_y -= 1;
	mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->position, sl->p_x * sl->img_width, sl->p_y * sl->img_width);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	t_sl	sl_cp;

	parsing(&sl, &sl_cp, argc, argv);
	init_img(&sl);
	init_map(&sl);
	mlx_key_hook(sl.mlx_win, ft_key, &sl);
	mlx_loop(sl.mlx);
	return (0);
}
