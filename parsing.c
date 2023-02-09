/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:47 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/09 15:32:14 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// doublons de E P?, un ;oins un collectible
// carte fermee
// chemin possible, backtracking TO DO
// compter lxL
// quitter proprement et "Error\nMessage\n"

// mettre dans un tab integr2 a une structure

// recursive, avance dans une direction puis revient en arriere quand bloqu2
// comme en tampon grace a al arecursive, puiune fois que plus aucune solution
// comte si le nombre de collectible est le meme aue necesaire. gardcer xy de p
// pour commencer le backtracking

//garder la position de P et E et C

void	check_arg(t_sl *sl, char **argv)
{
	int		fd;
	int		next_size;
	char	*next;
	char	*first;

	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_putstr_fd("Error\nMap extention is not .ber\n", 2), exit(0));
	fd = open(argv[1], O_RDONLY);
	first = get_next_line(fd);
	if (!first)
		return (ft_putstr_fd("Error\nNothintg to read\n", 2), exit(0));
	sl->x = ft_strlen(first) - 1;
	next = get_next_line(fd);
	while (next)
	{
		next_size = ft_strlen(next);
		if (next[next_size - 1] == '\n')
			next_size--;
		if (sl->x != next_size)
			return (ft_putstr_fd("Error\nMap is not regular\n", 2), exit(0));
		free(next);
		next = get_next_line(fd);
	}
	close(fd);
	free(next);
}

void	fill_map(t_sl *sl, char **argv)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	sl->map = malloc(sizeof(char *) * sl->y + 1);
	if (!sl->map)
		return ;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	sl->y = 0;
	while (str)
	{
		sl->map[i] = ft_substr(str, 0, sl->x);
		sl->y += 1;
		free(str);
		str = get_next_line(fd);
		i++;
	}
	sl->map[i] = NULL;
	close (fd);
	free(str);
}

void	parsing(t_sl *sl, t_sl *sl_cp, char **argv)
{
	check_arg(sl, argv);
	fill_map(sl, argv);
	// fill_map(sl_cp, argv);
	ft_printf("y : %d\nx : %d\n", sl->y, sl->x);
	check_error(sl, sl_cp);
	ft_printf("p_y : %d\np_x : %d\n", sl->p_y, sl->p_x);
}
