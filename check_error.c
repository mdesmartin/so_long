/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:07:15 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/08 16:37:10 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//check the number of collectibles, if thetre is a start
// and an exit and if the map is surounded by walls

void	print_map(char **map)
{
	int i = -1;

	ft_printf("Dommage bruh\n");
	while (map[++i])
		ft_printf("%s\n", map[i]);
}

void	check_walls(t_sl *sl)
{
	int	x;
	int	y;

	y = 0;
	print_map(sl->map);
	while (sl->map[y])
	{
		ft_printf("nil");
		x = 0;
		while (sl->map[y][x])
		{
			if ((x == 0 || x == sl->x || y == 0 || y == sl->y)
				&& sl->map[y][x] != 1)
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
	if (!map)
	y = 0;
	while (sl->map[y])
	{
		ft_printf("ici");
		x = 0;
		while (sl->map[y][x])
		{
			ft_printf("oui");
			if (sl->map[y][x] == 'P')
			{
				ft_printf("wesh");
				sl->p_x = x;
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

// void	check_endable(sl);
// {}

void	check_error(t_sl *sl)
{
	sl->nb_p = 0;
	sl->nb_e = 0;
	sl->nb_c = 0;

	print_map(sl->map);

	check_walls(sl);
	check_items(sl);

	ft_printf("%d\n", sl->nb_p);
	ft_printf("%d\n", sl->nb_e);
	ft_printf("%d\n", sl->nb_c);

	if (sl->nb_p != 1)
		return (ft_putstr_fd("Error\nToo many/few Positions, need one", 2) \
		, ft_free_tab(sl->map), exit(0));
	if (sl->nb_e != 1)
		return (ft_putstr_fd("Error\nToo many/few Exit, need one", 2) \
		, ft_free_tab(sl->map), exit(0));
	if (sl->nb_c == 0)
		return (ft_putstr_fd("Error\nToo few Collectible, \
		need at least one", 2), ft_free_tab(sl->map), exit(0));
	// check_enndable(sl);
}
