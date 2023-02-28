/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:19 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/28 10:57:37 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_to_stash(char *stash, char *buffer)
{
	char	*dst;

	dst = ft_strjoin(stash, buffer);
	free(stash);
	stash = NULL;
	return (dst);
}

char	*clean(char *stash)
{
	int		i;
	int		j;
	char	*cleaned;

	i = 0;
	j = 0;
	(void) j;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	cleaned = malloc(sizeof(char) * ft_strlen(stash) - i + 1);
	if (!(cleaned))
		return (free(stash), stash = NULL, NULL);
	i++;
	ft_strlcpy(cleaned, &stash[i], ft_strlen(stash) - i + 1);
	return (free(stash), stash = NULL, cleaned);
}

char	*fill(char *stash, char *line)
{
	int	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!(line))
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*read_n_join(char *stash, int fd)
{
	int		readed;
	char	buf[BUFFER_SIZE + 1];

	if (!(stash))
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	readed = 1;
	while (readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		buf[readed] = '\0';
		stash = add_to_stash(stash, buf);
		if (!stash)
			return (NULL);
		if (ft_strrchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	line = NULL;
	stash = read_n_join(stash, fd);
	if (!stash)
		return (stash = NULL, NULL);
	line = fill(stash, line);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = clean(stash);
	return (line);
}
