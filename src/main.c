/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/02 13:35:37 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_sl	sl;
	t_sl	sl_cp;

	parsing(&sl, &sl_cp, argc, argv);
	init_mlx(&sl);
	init_map(&sl, &sl_cp);
	mlx_key_hook(sl.mlx_win, ft_key, &sl);
	mlx_hook(sl.mlx_win, 17, 0L, free_n_close, &sl);
	mlx_loop(sl.mlx);
	return (0);
}
