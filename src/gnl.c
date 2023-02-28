/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:58:07 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/28 10:59:03 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	file_size(char *pathname)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error_map(NULL, 3, "File : Failed to open\n");
	size = 1;
	while (read(fd, &buff, 1))
		size++;
	close(fd);
	return (size);
}

char	**get_map(char *pathname)
{
	char	**map;
	char	*line;
	int		fd;
	int		size;

	size = file_size(pathname);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error_map(NULL, 3, "File : Failed to open\n");
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		ft_error_map(NULL, 12, NULL);
	if (read (fd, line, size) == -1)
	{
		close(fd);
		free(line);
		ft_error_map(NULL, 5, "File : Failed to read\n");
	}
	close(fd);
	map = ft_split(line, '\n');
	free(line);
	if (!map)
		ft_error_map(NULL, 12, NULL);
	return (map);
}
