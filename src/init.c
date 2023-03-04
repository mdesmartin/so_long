/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:12 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/04 16:31:19 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img2(t_sl *sl)
{
	sl->exit = mlx_xpm_file_to_image(sl->mlx, \
		"img/exit.xpm", &sl->img_width, &sl->img_height);
	if (!sl->exit)
		error_n_close("Error\nMissing exit image\n", sl);
	sl->open_exit = mlx_xpm_file_to_image(sl->mlx, \
		"img/open_exit.xpm", &sl->img_width, &sl->img_height);
	if (!sl->open_exit)
		error_n_close("Error\nMissing open_exit image\n", sl);
	sl->hidden_exit = mlx_xpm_file_to_image(sl->mlx, \
		"img/hidden_exit.xpm", &sl->img_width, &sl->img_height);
	if (!sl->hidden_exit)
		error_n_close("Error\nMissing hidden_exit image\n", sl);
	sl->player = mlx_xpm_file_to_image(sl->mlx, \
		"img/player.xpm", &sl->img_width, &sl->img_height);
	if (!sl->player)
		error_n_close("Error\nMissing player image\n", sl);
}

void	init_img(t_sl *sl)
{
	sl->wall = mlx_xpm_file_to_image(sl->mlx, \
		"img/wall.xpm", &sl->img_width, &sl->img_height);
	if (!sl->wall)
		error_n_close("Error\nMissing wall image\n", sl);
	sl->floor = mlx_xpm_file_to_image(sl->mlx, \
		"img/floor.xpm", &sl->img_width, &sl->img_height);
	if (!sl->floor)
		error_n_close("Error\nMissing floor image\n", sl);
	sl->collectible = mlx_xpm_file_to_image(sl->mlx, \
		"img/collectible.xpm", &sl->img_width, &sl->img_height);
	if (!sl->collectible)
		error_n_close("Error\nMissing collectible image\n", sl);
}

void	init_mlx(t_sl *sl)
{
	sl->move = 1;
	sl->img_width = 64;
	sl->img_height = 64;
	sl->mlx = NULL;
	sl->mlx_win = NULL;
	sl->wall = NULL;
	sl->floor = NULL;
	sl->collectible = NULL;
	sl->exit = NULL;
	sl->open_exit = NULL;
	sl->hidden_exit = NULL;
	sl->player = NULL;
	sl->mlx = mlx_init();
	if (!sl->mlx)
		error_n_close("Error\nProblem while creating mlx ptr\n", sl);
	init_img(sl);
	init_img2(sl);
	sl->mlx_win = mlx_new_window(sl->mlx, \
		sl->img_width * sl->x, sl->img_height * sl->y, "so_long");
	if (!sl->mlx_win)
		error_n_close("Error\nProblem while creating mlx win\n", sl);
}

void	init_map(t_sl *sl, t_sl *sl_cp)
{
	sl_cp->y = 0;
	while (sl->map[sl_cp->y])
	{
		sl_cp->x = 0;
		while (sl->map[sl_cp->y][sl_cp->x])
		{
			if (sl->map[sl_cp->y][sl_cp->x] == '0')
				display_img(sl, sl_cp->y, sl_cp->x, '0');
			else if (sl->map[sl_cp->y][sl_cp->x] == '1')
				display_img(sl, sl_cp->y, sl_cp->x, '1');
			else if (sl->map[sl_cp->y][sl_cp->x] == 'P')
				display_img(sl, sl_cp->y, sl_cp->x, 'P');
			else if (sl->map[sl_cp->y][sl_cp->x] == 'E')
				display_img(sl, sl_cp->y, sl_cp->x, 'E');
			else if (sl->map[sl_cp->y][sl_cp->x] == 'C')
				display_img(sl, sl_cp->y, sl_cp->x, 'C');
			sl_cp->x++;
		}
		sl_cp->y++;
	}
}
