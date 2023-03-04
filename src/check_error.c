/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:07:15 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/04 16:52:55 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_sl *sl, t_sl *sl_cp)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] != '1' && sl->map[y][x] != '0'
				&& sl->map[y][x] != 'P' && sl->map[y][x] != 'C'
				&& sl->map[y][x] != 'E')
				return (ft_putstr_fd("Error\nForbidden char in map\n", 2), \
				ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
			if ((x == 0 || x == sl->x - 1 || y == 0
					|| y == sl->y - 1) && sl->map[y][x] != '1')
				return (ft_putstr_fd("Error\nMissing wall\n", 2) \
				, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
			x++;
		}
		y++;
	}
}

void	check_items(t_sl *sl, t_sl *sl_cp)
{
	sl_cp->y = 0;
	while (sl->map[sl_cp->y])
	{
		sl_cp->x = 0;
		while (sl->map[sl_cp->y][sl_cp->x])
		{
			if (sl->map[sl_cp->y][sl_cp->x] == 'P')
			{
				sl->player_x = sl_cp->x;
				sl->player_y = sl_cp->y;
				sl->nb_p += 1;
			}
			if (sl->map[sl_cp->y][sl_cp->x] == 'E')
			{
				sl->exit_x = sl_cp->x;
				sl->exit_y = sl_cp->y;
				sl->nb_e += 1;
			}
			if (sl->map[sl_cp->y][sl_cp->x] == 'C')
				sl->nb_c += 1;
			sl_cp->x++;
		}
		sl_cp->y++;
	}
}

void	check_error(t_sl *sl, t_sl *sl_cp)
{
	sl->nb_p = 0;
	sl->nb_e = 0;
	sl->nb_c = 0;
	sl_cp->nb_c = 0;
	sl_cp->nb_e = 0;
	check_walls(sl, sl_cp);
	check_items(sl, sl_cp);
	if (sl->nb_p != 1)
		return (ft_putstr_fd("Error\nOne player needed\n", 2) \
		, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
	if (sl->nb_e != 1)
		return (ft_putstr_fd("Error\nOne exit needed\n", 2) \
		, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
	if (sl->nb_c == 0)
		return (ft_putstr_fd("Error\nToo few Collectible\n", 2), \
		ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
}
