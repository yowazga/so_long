/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:36:58 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/15 12:13:29 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen_2(s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
