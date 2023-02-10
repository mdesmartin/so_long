/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/10 17:17:01 by mvogel           ###   ########lyon.fr   */
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

	void			*mlx_win;
	void			*mlx;

	int				img_width;
	int				img_height;

	char			*path_wall;
	char			*path_floor;
	char			*path_collectible;
	char			*path_exit;
	char			*path_position;

	void			*wall;
	void			*floor;
	void			*collectible;
	void			*exit;
	void			*position;
}					t_sl;

void	parsing(t_sl *sl, t_sl *sl_cp, int argc, char **argv);
void	check_error(t_sl *sl, t_sl *cp);

#endif
