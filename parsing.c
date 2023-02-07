/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:47 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/07 16:58:01 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// doublons de E P?, un ;oins un collectible
// carte fermee
// chemin possible, backtracking
// compter lxL
// quitter proprement et "Error\nMessage\n"

// mettre dans un tab integr2 a une structure

// recursive, avance dans une direction puis revient en arriere quand bloqu2
// comme en tampon grace a al arecursive, puiune fois que plus aucune solution
// comte si le nombre de collectible est le meme aue necesaire. gardcer xy de p
// pour commencer le backtracking

void	parsing(int argc, char **argv)
{
	int	l;
	char	*next;
	char	*first;

	l = ft_strlen(argv[1]);
	if (&argv[1][l - 4] != ".ber")
		return (ft_putstr_fd("Error\nMap extention is not .ber", 2));

// mesure la map
	first = get_next_line(open(argv[1], O_RDONLY));
	if (!first)
		return (ft_putstr_fd("Error\nNothing to read", 2));
	else
		struct. = 1;
	while (next)
	{
		free(next);
		next = get_next_line(open(argv[1], O_RDONLY));
		struct.width += 1
		if (ft_strlen(first) != ft_strlen(next))
			return (ft_putstr_fd("Error\nMap width is not regular", 2));
	}

}
