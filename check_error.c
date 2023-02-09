/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:07:15 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/09 15:31:41 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int i = -1;

	while (map[++i])
		ft_printf("%s\n", map[i]);
}

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
			if ((x == 0 || x == sl->x - 1 || y == 0
					|| y == sl->y - 1) && sl->map[y][x] != '1')
				return (ft_putstr_fd("Error\nMissing wall", 2) \
				, ft_free_tab(sl->map), exit(0));
			x++;
		}
		y++;
	}
}

void	check_items(t_sl *sl)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == 'P')
			{
				sl->p_x = x + 1;
				sl->p_y = y;
				sl->nb_p += 1;
			}
			if (sl->map[y][x] == 'E')
				sl->nb_e += 1;
			if (sl->map[y][x] == 'C')
				sl->nb_c += 1;
			x++;
		}
		y++;
	}
}

void	check_end(int y, int x, t_sl *cp)
{
	if (cp->map[y][x] == 'C')
		cp->nb_c += 1;
	if (cp->map[y][x] == 'E')
		cp->nb_e += 1;
	
	print_map(cp->map);
	cp->map[y][x] = '1';
	if (cp->map[y - 1][x] != '1')
		check_end(y - 1, x, cp);
	if (cp->map[y][x + 1] != '1')
		check_end(y, x + 1, cp);
	if (cp->map[y + 1][x] != '1')
		check_end(y + 1, x, cp);
	if (cp->map[y][x - 1] != '1')
		check_end(y, x - 1, cp);
}

void	check_error(t_sl *sl, t_sl *cp)
{
	sl->nb_p = 0;
	sl->nb_e = 0;
	sl->nb_c = 0;

	print_map(sl->map);

	check_walls(sl);
	check_items(sl);

	ft_printf("P : %d\n", sl->nb_p);
	ft_printf("E : %d\n", sl->nb_e);
	ft_printf("C : %d\n", sl->nb_c);

	if (sl->nb_p != 1)
		return (ft_putstr_fd("Error\nToo many/few positions, need one", 2) \
		, ft_free_tab(sl->map), exit(0));
	if (sl->nb_e != 1)
		return (ft_putstr_fd("Error\nToo many/few exit, need one", 2) \
		, ft_free_tab(sl->map), exit(0));
	if (sl->nb_c == 0)
		return (ft_putstr_fd("Error\nToo few Collectible, \
		need at least one", 2), ft_free_tab(sl->map), exit(0));
	(void) cp;
	// int x;
	// int y;

	// y = cp->p_y;
	// x = cp->p_x;
	// // check_end(y, x, cp);
}
