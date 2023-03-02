/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:14:51 by mehdidesmar       #+#    #+#             */
/*   Updated: 2023/03/02 13:35:28 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	y_size(t_sl *sl)
{
	int	i;

	i = 0;
	while (sl->map[i])
		i++;
	return (i);
}

int	x_size(t_sl *sl)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(sl->map[0]);
	while (sl->map[i])
	{
		if (len != ft_strlen(sl->map[i]))
			return (-1);
		i++;
	}
	return ((int) len);
}

void	check_map(t_sl *sl, t_sl *sl_cp)
{
	sl->y = y_size(sl);
	sl->x = x_size(sl);
	if (sl->y == 0 || sl->x == -1)
	{
		ft_free_tab(sl->map);
		ft_free_tab(sl_cp->map);
		error_n_exit("Error\nMap is not rectangular\n");
	}
}
