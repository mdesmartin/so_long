/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/15 16:35:35 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_n_close(t_sl *sl)
{
	ft_free_tab(sl->map);
	mlx_destroy_window(sl->mlx, sl->mlx_win);
	mlx_destroy_image(sl->mlx, sl->wall);
	mlx_destroy_image(sl->mlx, sl->floor);
	mlx_destroy_image(sl->mlx, sl->collectible);
	mlx_destroy_image(sl->mlx, sl->exit);
	mlx_destroy_image(sl->mlx, sl->open_exit);
	mlx_destroy_image(sl->mlx, sl->position);
	mlx_destroy_display(sl->mlx);
	free(sl->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	t_sl	sl_cp;

	parsing(&sl, &sl_cp, argc, argv);
	init_img(&sl, &sl_cp);
	init_map(&sl, &sl_cp);
	mlx_key_hook(sl.mlx_win, ft_key, &sl);
	mlx_hook(sl.mlx_win, 17, 0L, free_n_close, &sl);
	mlx_loop(sl.mlx);
	return (0);
}

//	image a hcaque fois, zindoozs, display, free mlx
