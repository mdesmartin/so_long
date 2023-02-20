/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/20 12:23:50 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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

#endif
