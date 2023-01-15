/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:59:14 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/15 12:13:14 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_size(t_demensions size, t_game *play)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (play->map[i++])
		check++;
	if (check != size.vertical)
	{
		write(1, "Error\nThe map is not rectangular", 32);
		free(play->map);
		exit(1);
	}
	if (size.vertical > 17 || size.horizontal > 32)
	{
		write(1, "Error\nyour map too large", 24);
		free(play->map);
		exit(1);
	}
}

int static	count_word(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] != c && str[i])
				i++;
			count++;
		}
	}
	return (count);
}

int static	count_char(char *str, char c, int *start)
{
	int	i;

	i = 0;
	while (str[*start] && str[*start] != c)
	{
		(*start)++;
		i++;
	}
	return (i);
}

void static	ft_cpy(char **str, char *s, char c, int cw)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < cw)
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			str[i][j++] = s[k++];
		str[i][j] = 0;
		i++;
	}
	str[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	if (s)
	{
		counter = count_word((char *)s, c);
		tab = (char **)malloc((counter + 1) * sizeof(char *));
		if (!tab)
			return (0);
		while (i < counter)
		{
			while (s[j] == c)
				j++;
			tab[i++] = (char *)malloc(count_char((char *)s, c, &j) + 1);
			if (!s[i - 1])
				return (0);
		}
		ft_cpy(tab, (char *)s, c, counter);
		return (tab);
	}
	return (0);
}
