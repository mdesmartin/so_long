void	print_map(char **map)
{
	int i = -1;

	while (map[++i])
		ft_printf("%s\n", map[i]);
	ft_printf("\n");
}

//move on door ? collectible turn on themself ? sprite of character ? check makefile titi-rex