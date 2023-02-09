/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/09 15:29:22 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_sl
{
	char			**map;
	int				x;
	int				y;

	int				p_x;
	int				p_y;

	int				nb_p;
	int				nb_e;
	int				nb_c;
}					t_sl;

void	parsing(t_sl *sl, t_sl *sl_cp, char **argv);
void	check_error(t_sl *sl, t_sl *cp);


#endif
