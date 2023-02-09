/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/09 17:06:23 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int i = -1;

	while (map[++i])
		ft_printf("%s\n", map[i]);
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	t_sl	sl_cp;

	(void) argc;
	parsing(&sl, &sl_cp, argv);
}
