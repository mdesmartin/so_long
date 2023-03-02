/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:47 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/02 13:35:44 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_size(char **argv)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_n_exit("Error\nFailed to open map\n");
	size = 1;
	while (read(fd, &buff, 1))
		size++;
	close(fd);
	return (size);
}

void	fill_map(t_sl *sl, char **argv)
{
	char	*line;
	int		fd;
	int		size;

	size = file_size(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_n_exit("Error\nFailed to open map\n");
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		error_n_exit("Error\nFailed to malloc map\n");
	if (read (fd, line, size) == -1)
	{
		close(fd);
		free(line);
		error_n_exit("Error\nFailed to read map\n");
	}
	close(fd);
	sl->map = ft_split(line, '\n');
	free(line);
	if (!sl->map)
		error_n_exit("Error\nFailed to split map\n");
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
	if (argc != 2)
		return (ft_putstr_fd("Error\nOne map needed in argument\n", 2), exit(0));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_putstr_fd("Error\nMap extention is not .ber\n", 2), exit(0));
	fill_map(sl, argv);
	fill_map(sl_cp, argv);
	check_map(sl, sl_cp);
	check_error(sl, sl_cp);
	check_end(sl->player_y, sl->player_x, sl_cp);
	if (sl_cp->nb_e != 1)
		return (ft_putstr_fd("Error\nThe map cannot be finished\n", 2) \
		, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
	if (sl_cp->nb_c != sl->nb_c)
		return (ft_putstr_fd("Error\nCannot collect all collectibles\n", 2) \
		, ft_free_tab(sl->map), ft_free_tab(sl_cp->map), exit(0));
	ft_free_tab(sl_cp->map);
}
