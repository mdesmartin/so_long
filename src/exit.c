/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:34:09 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/04 01:40:16 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_n_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	error_n_close(char *msg, t_sl *sl)
{
	ft_putstr_fd(msg, 2);
	free_n_close(sl);
}

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
	if (sl->hidden_exit != NULL)
		mlx_destroy_image(sl->mlx, sl->hidden_exit);
	if (sl->position != NULL)
		mlx_destroy_image(sl->mlx, sl->position);
	if (sl->mlx != NULL)
	{
		mlx_destroy_display(sl->mlx);
		free(sl->mlx);
	}
	exit(0);
}
