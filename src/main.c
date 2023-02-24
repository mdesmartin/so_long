/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/24 16:01:13 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_n_close(t_sl *sl)
{
	ft_free_tab(sl->map);
	if (sl->mlx_win != NULL)
		mlx_destroy_window(sl->mlx, sl->mlx_win);
	if (sl->wall != NULL)
		mlx_destroy_image(sl->mlx, sl->wall);
	if (sl->floor != NULL)
		mlx_destroy_image(sl->mlx, sl->floor);
	if (sl->collectible != NULL)
		mlx_destroy_image(sl->mlx, sl->collectible);
	if (sl->exit != NULL)
		mlx_destroy_image(sl->mlx, sl->exit);
	if (sl->open_exit != NULL)
		mlx_destroy_image(sl->mlx, sl->open_exit);
	if (sl->position != NULL)
		mlx_destroy_image(sl->mlx, sl->position);
	if (sl->mlx != NULL)
	{
		mlx_destroy_display(sl->mlx);
		free(sl->mlx);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	t_sl	sl_cp;

	parsing(&sl, &sl_cp, argc, argv);
	init_mlx(&sl, &sl_cp);
	init_map(&sl, &sl_cp);
	mlx_key_hook(sl.mlx_win, ft_key, &sl);
	mlx_hook(sl.mlx_win, 17, 0L, free_n_close, &sl);
	mlx_loop(sl.mlx);
	return (0);
}
