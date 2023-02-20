/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:19:06 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/20 13:07:27 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structures.h"

void	parsing(t_sl *sl, t_sl *sl_cp, int argc, char **argv);
void	check_error(t_sl *sl, t_sl *cp);
int		ft_key(int key, t_sl *sl, t_sl *sl_cp);
void	init_map(t_sl *sl, t_sl *sl_cp);
void	init_img(t_sl *sl, t_sl *sl_cp);
int		free_n_close(t_sl *sl);

#endif
