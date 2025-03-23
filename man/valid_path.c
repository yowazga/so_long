/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:58:45 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/15 11:30:39 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	check_path(char **map, int i, int j)
{
	map[i][j] = WALL;
	if (map[i + 1][j] != WALL)
		check_path(map, i + 1, j);
	if (map[i - 1][j] != WALL)
		check_path(map, i - 1, j);
	if (map[i][j + 1] != WALL)
		check_path(map, i, j + 1);
	if (map[i][j - 1] != WALL)
		check_path(map, i, j - 1);
}

static void	last_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == DOOR || map[i][j] == COIN)
			{
				write(1, "Error\nyou have invalid path!", 28);
				exit(1);
			}
			j++;
		}
		i ++;
	}
}

static void	check_player_path(char **map, t_demensions position_p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
			{
				position_p.vertical = i;
				position_p.horizontal = j;
				break ;
			}
			j++;
		}
		i++;
	}
	check_path(map, position_p.vertical, position_p.horizontal);
	last_check(map);
}

void	chack_valid_path(char **map, t_demensions s_win, t_game *play)
{
	char	**map_2;
	int		i;

	i = 0;
	map_2 = malloc(sizeof(char *) * (s_win.vertical) + 1);
	if (!map_2)
		return ;
	while (i < s_win.vertical)
	{
		map_2[i] = ft_strdup(map[i]);
		i++;
	}
	map_2[i] = NULL;
	check_player_path(map_2, play->p_play);
	free_2_map(map_2);
}
