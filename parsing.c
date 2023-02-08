/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:47 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/08 16:11:05 by mvogel           ###   ########lyon.fr   */
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
	int		len;
	char	*next;
	char	*first;

	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (ft_putstr_fd("Error\nMap extention is not .ber\n", 2), exit(0));
	first = get_next_line(open(argv[1], O_RDONLY));
	if (!first)
		return (ft_putstr_fd("Error\nNothintg to read\n", 2), exit(0));
	sl->x = ft_strlen(first) + 1;
	sl->y = 1;
	next = get_next_line(open(argv[1], O_RDONLY));
	while (next)
	{
		if (sl->x != (int)ft_strlen(next))
			return (ft_putstr_fd("Error\nMap is not regular\n", 2), exit(0));
		sl->y += 1;
		free(next);
		next = get_next_line(open(argv[1], O_RDONLY));
	}
	free(next);
}

void	fill_map(t_sl *sl, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	sl->map = malloc(sizeof(char *) * sl->y + 1);
	if (!sl->map)
		return ;
	str = get_next_line(open(argv[1], O_RDONLY));
	while (str)
	{
		sl->map[i] = ft_substr(str, 0, sl->x);
		free(str);
		str = get_next_line(open(argv[1], O_RDONLY));
		i++;
	}
	free(str);
}

void	parsing(t_sl *sl, char **argv)
{
	check_arg(sl, argv);
	fill_map(sl, argv);
	check_error(sl);
}
