/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:07:15 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/16 10:39:38 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_sl *sl)
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
				ft_free_tab(sl->map), exit(0));
			if ((x == 0 || x == sl->x - 1 || y == 0
					|| y == sl->y - 1) && sl->map[y][x] != '1')
				return (ft_putstr_fd("Error\nMissing wall\n", 2) \
				, ft_free_tab(sl->map), exit(0));
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

void	check_error(t_sl *sl, t_sl *cp)
{
	sl->nb_p = 0;
	sl->nb_e = 0;
	sl->nb_c = 0;
	cp->nb_c = 0;
	cp->nb_e = 0;
	check_walls(sl);
	check_items(sl, cp);
	if (sl->nb_p != 1)
		return (ft_putstr_fd("Error\nToo many/few position, only one needed", 2) \
		, ft_free_tab(sl->map), exit(0));
	if (sl->nb_e != 1)
		return (ft_putstr_fd("Error\nToo many/few exit, only one needed", 2) \
		, ft_free_tab(sl->map), exit(0));
	if (sl->nb_c == 0)
		return (ft_putstr_fd("Error\nToo few Collectible, \
		at least one needed", 2), ft_free_tab(sl->map), exit(0));
}
