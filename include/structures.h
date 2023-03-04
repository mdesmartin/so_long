/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/04 01:24:58 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
	void			*position;
}					t_sl;

#endif
