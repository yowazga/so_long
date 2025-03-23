/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:53:23 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/09 09:10:42 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_first_last(char **map, t_demensions s_win)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s_win.vertical - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != WALL)
			{
				write(1, "Eroor\nThe map is not closed/surrounded by walls", 47);
				free_2_map(map);
				exit(1);
			}
			j++;
		}
		i += s_win.vertical - 1;
	}
}

static void	check_wall(char **map, t_demensions s_win)
{
	int	i;

	i = 0;
	check_first_last(map, s_win);
	while (i < s_win.vertical)
	{
		if (map[i][0] != WALL || map[i][s_win.horizontal - 1] != WALL)
		{
			write(1, "Eroor\nThe map is not closed/surrounded by walls", 47);
			free_2_map(map);
			exit(1);
		}
		i++;
	}
}

static int	check_content(char **map, t_demensions s_win)
{
	int	i;
	int	j;
	int	play;

	(void)s_win;
	i = -1;
	play = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != WALL && map[i][j] != SPACE && map[i][j] != DOOR &&
				map[i][j] != COIN && map[i][j] != PLAYER && map[i][j] != ENEMY)
			{
				write(1, "Error\nther is a uncknow charachter", 34);
				free_2_map(map);
				exit(1);
			}
			if (map[i][j] == PLAYER)
				play++;
			j++;
		}
	}
	return (play);
}

static void	cont_content(char **map)
{
	int	i;
	int	j;
	int	e;
	int	c;

	i = -1;
	e = 0;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == COIN)
				c++;
			else if (map[i][j] == DOOR)
				e++;
		}
	}
	if (e != 1 || c < 1)
	{
		write(1, "Eroor\ncheck number Collect or Exit", 34);
		free_2_map(map);
		exit(1);
	}
}

void	check_map(char **map, t_demensions s_window, t_game *play)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (s_window.horizontal != ft_strlen_2(map[i]))
		{
			write(1, "Error\nThe map is not rectangular", 32);
			free_2_map(map);
			exit(1);
		}
		i++;
	}
	check_wall(map, s_window);
	if (check_content(map, s_window) != 1)
	{
		write(1, "Error\ncheck number player", 25);
		free_2_map(map);
		exit(1);
	}
	cont_content(map);
	chack_valid_path(map, s_window, play);
}
