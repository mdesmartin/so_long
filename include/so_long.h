/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/06 16:55:29 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct s_sl
{
	char			**map;
	int				fd;
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
	void			*hidden_exit;
	void			*player;
}					t_sl;

void	parsing(t_sl *sl, t_sl *sl_cp, int argc, char **argv);
void	check_error(t_sl *sl, t_sl *cp);
int		ft_key(int key, t_sl *sl);
void	init_map(t_sl *sl, t_sl *sl_cp);
void	init_mlx(t_sl *sl);
int		free_n_close(t_sl *sl);
void	error_n_exit(char *msg);
void	error_n_close(char *msg, t_sl *sl);
void	check_map(t_sl *sl, t_sl *sl_cp);
void	display_img(t_sl *sl, int y, int x, char img);

#endif
