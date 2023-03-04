/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:12 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/04 01:43:20 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	sl->position = mlx_xpm_file_to_image(sl->mlx, \
		"img/position.xpm", &sl->img_width, &sl->img_height);
	if (!sl->position)
		error_n_close("Error\nMissing position image\n", sl);
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
	sl->position = NULL;
	sl->mlx = mlx_init();
	if (!sl->mlx)
		error_n_close("Error\nProblem while creating mlx ptr\n", sl);
	init_img(sl);
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
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
				sl->floor, sl_cp->x * sl->img_width, sl_cp->y * sl->img_width);
			else if (sl->map[sl_cp->y][sl_cp->x] == '1')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
				sl->wall, sl_cp->x * sl->img_width, sl_cp->y * sl->img_width);
			else if (sl->map[sl_cp->y][sl_cp->x] == 'P')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->position, \
				sl_cp->x * sl->img_width, sl_cp->y * sl->img_width);
			else if (sl->map[sl_cp->y][sl_cp->x] == 'E')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
				sl->exit, sl_cp->x * sl->img_width, sl_cp->y * sl->img_width);
			else if (sl->map[sl_cp->y][sl_cp->x] == 'C')
				mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->collectible, \
				sl_cp->x * sl->img_width, sl_cp->y * sl->img_width);
			sl_cp->x++;
		}
		sl_cp->y++;
	}
}

int	can_move(char next, t_sl *sl)
{
	if (next == 'E')
	{
		if (!sl->nb_c)
			free_n_close(sl);
		else
		{
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->hidden_exit, \
			sl->exit_x * sl->img_width, sl->exit_y * sl->img_width);
			ft_printf("%d\n", sl->move++);
			return (1);
		}
	}
	else if (next == '1')
		return (0);
	else if (next == 'C')
	{
		sl->nb_c -= 1;
		if (!sl->nb_c)
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->open_exit, \
			sl->exit_x * sl->img_width, sl->exit_y * sl->img_width);
		ft_printf("%d\n", sl->move++);
		return (1);
	}
	else
	{
		ft_printf("%d\n", sl->move++);
		return (1);
	}
	return (0);
}

int	ft_key(int key, t_sl *sl)
{
	(void) sl;
	if (key == 65307)
		free_n_close(sl);
	if (key == 100 || key == 97 || key == 115 || key == 119)
	{
		if (sl->map[sl->player_y][sl->player_x] == 'E')
		{
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->exit, \
			sl->exit_x * sl->img_width, sl->exit_y * sl->img_width);
		}
		else
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->floor, \
			sl->player_x * sl->img_width, sl->player_y * sl->img_width);
		if (key == 100 && can_move(sl->map[sl->player_y][sl->player_x + 1], \
		sl))
			sl->player_x += 1;
		else if (key == 97
			&& can_move(sl->map[sl->player_y][sl->player_x - 1], sl))
			sl->player_x -= 1;
		else if (key == 115
			&& can_move(sl->map[sl->player_y + 1][sl->player_x], sl))
			sl->player_y += 1;
		else if (key == 119
			&& can_move(sl->map[sl->player_y - 1][sl->player_x], sl))
			sl->player_y -= 1;
		if (sl->map[sl->player_y][sl->player_x] == 'C')
			sl->map[sl->player_y][sl->player_x] = '0';
		if (sl->map[sl->player_y][sl->player_x] == 'E')
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->hidden_exit, \
			sl->exit_x * sl->img_width, sl->exit_y * sl->img_width);
		else
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, sl->position, \
			sl->player_x * sl->img_width, sl->player_y * sl->img_width);
	}
	return (0);
}
