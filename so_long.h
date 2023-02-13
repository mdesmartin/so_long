/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/13 17:47:50 by mvogel           ###   ########lyon.fr   */
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

	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;

	int				move;

	int				nb_p;
	int				nb_e;
	int				nb_c;

	void			*mlx_win;
	void			*mlx;

	int				img_width;
	int				img_height;

	void			*wall;
	void			*floor;
	void			*collectible;
	void			*exit;
	void			*open_exit;
	void			*position;
}					t_sl;

void	parsing(t_sl *sl, t_sl *sl_cp, int argc, char **argv);
void	check_error(t_sl *sl, t_sl *cp);
int		ft_key(int key, t_sl *sl, t_sl *sl_cp);
void	init_map(t_sl *sl, t_sl *sl_cp);
void	init_img(t_sl *sl, t_sl *sl_cp);
int		free_n_close(t_sl *sl);

#endif
