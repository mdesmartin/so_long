/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:47 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/28 10:43:18 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_n_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}


void	check_malloc(char *str, int fd, char *msg)
{
	if (!str)
	{
		close(fd);
		error_n_exit(msg);
	}
}


int	check_map(t_sl *sl, char **argv)
{
	int		fd;
	int		next_size;
	char	*next;
	int		error;

	error = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_n_exit("Error\nMap not opened\n");
	next = get_next_line(fd);
	check_malloc(next, fd, "Error\nNothintg to read\n");
	sl->x = ft_strlen(next) - 1;
	sl->y = 0;
	while (next)
	{
		next_size = ft_strlen(next);
		if (next[next_size - 1] == '\n')
			next_size--;
		if (sl->x != next_size)
			error = 1;
		sl->y += 1;
		free(next);
		next = get_next_line(fd);
	}
	if (error == 1)
		return (free(next), close(fd), \
		error_n_exit("Error\nMap is not regular\n"), 0);
	return (free(next), close(fd));
}

void	fill_map(t_sl *sl, char **argv)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;

	sl->map = malloc(sizeof(char *) * (sl->y + 1));
	if (!sl->map)
		return (error_n_exit("Error\nCan't create map\n"));

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_n_exit("Error\nMap not opened\n");

	str = get_next_line(fd);
	check_malloc(str, fd, "Error\nNothintg to read\n"); //free(sl->map)


	while (str)
	{
		sl->map[i] = ft_substr(str, 0, sl->x);
		free(str);
		str = get_next_line(fd);
		i++; 
	}
	if (i != sl->y)
		error
	sl->map[i] = NULL;
	close (fd);
	free(str);
}

void	check_end(int y, int x, t_sl *cp)
{
	if (cp->map[y][x] == 'C')
		cp->nb_c += 1;
	if (cp->map[y][x] == 'E')
		cp->nb_e += 1;
	cp->map[y][x] = '1';
	if (cp->map[y - 1][x] != '1')
		check_end(y - 1, x, cp);
	if (cp->map[y][x + 1] != '1')
		check_end(y, x + 1, cp);
	if (cp->map[y + 1][x] != '1')
		check_end(y + 1, x, cp);
	if (cp->map[y][x - 1] != '1')
		check_end(y, x - 1, cp);
}

void	parsing(t_sl *sl, t_sl *sl_cp, int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 2)
		return (ft_putstr_fd("Error\nOne map needed in argument\n", 2), exit(0));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_putstr_fd("Error\nMap extention is not .ber\n", 2), exit(0));
	check_map(sl, argv);
	sl_cp->y = sl->y;
	sl_cp->x = sl->x;
	fill_map(sl, argv);
	fill_map(sl_cp, argv);
	check_error(sl, sl_cp);
	y = sl->player_y;
	x = sl->player_x;
	check_end(y, x, sl_cp);
	if (sl_cp->nb_e != 1)
		return (ft_putstr_fd("Error\nThe map cannot be finished\n", 2) \
		, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
	if (sl_cp->nb_c != sl->nb_c)
		return (ft_putstr_fd("Error\nCannot collect all collectibles\n", 2) \
		, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
	ft_free_tab(sl_cp->map);
}
