/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:14:25 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/08 15:53:13 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

static int	ft_numb_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		numb_word;
	int		len_word;
	int		i;

	numb_word = ft_numb_word(s, c);
	split = malloc(sizeof(char *) * (numb_word + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < numb_word)
	{
		while (*s == c)
			s++;
		len_word = ft_len_word(s, c);
		split[i] = ft_substr(s, 0, len_word);
		if (!split[i])
			return (ft_free_tab(split));
		i++;
		s += len_word;
	}
	split[i] = NULL;
	return (split);
}
