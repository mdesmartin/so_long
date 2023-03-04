/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:12 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/04 16:45:24 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_img(t_sl *sl, int y, int x, char img)
{
	if (img == '0')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->floor, x * sl->img_width, y * sl->img_width);
	if (img == '1')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->wall, x * sl->img_width, y * sl->img_width);
	if (img == 'P')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->player, x * sl->img_width, y * sl->img_width);
	if (img == 'E')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->exit, x * sl->img_width, y * sl->img_width);
	if (img == 'O')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->open_exit, x * sl->img_width, y * sl->img_width);
	if (img == 'H')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->hidden_exit, x * sl->img_width, y * sl->img_width);
	if (img == 'C')
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, \
		sl->collectible, x * sl->img_width, y * sl->img_width);
}

int	can_move(char next, t_sl *sl)
{
	if (next == '1')
		return (0);
	if (next == 'E')
	{
		if (!sl->nb_c)
			free_n_close(sl);
		else
			display_img(sl, sl->exit_y, sl->exit_x, 'H');
	}
	else if (next == 'C')
	{
		sl->nb_c -= 1;
		if (!sl->nb_c)
			display_img(sl, sl->exit_y, sl->exit_x, 'O');
	}
	ft_printf("%d\n", sl->move++);
	return (1);
}

void	move_player(t_sl *sl, int key)
{
	if (key == 100 \
		&& can_move(sl->map[sl->player_y][sl->player_x + 1], sl))
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
}

int	ft_key(int key, t_sl *sl)
{
	(void) sl;
	if (key == 65307)
		free_n_close(sl);
	if (key == 100 || key == 97 || key == 115 || key == 119)
	{
		if (sl->map[sl->player_y][sl->player_x] == 'E')
			display_img(sl, sl->exit_y, sl->exit_x, 'E');
		else
			display_img(sl, sl->player_y, sl->player_x, '0');
		move_player(sl, key);
		if (sl->map[sl->player_y][sl->player_x] == 'C')
			sl->map[sl->player_y][sl->player_x] = '0';
		if (sl->map[sl->player_y][sl->player_x] == 'E')
			display_img(sl, sl->exit_y, sl->exit_x, 'H');
		else
			display_img(sl, sl->player_y, sl->player_x, 'P');
	}
	return (0);
}
