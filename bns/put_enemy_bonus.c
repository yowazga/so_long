/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:11:39 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/09 12:05:21 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_check(t_game *play, char **map, int x, int y)
{
	static int	n;

	if (map[x - 1][y] != SPACE)
		n = 1;
	if (map[x + 1][y] != SPACE)
		n = 0;
	if ((map[x - 1][y] == SPACE) && (n == 0))
	{
		map[x - 1][y] = ENEMY;
		map[x][y] = SPACE;
	}
	if ((map[x + 1][y] == SPACE) && (n == 1))
	{
		map[x + 1][y] = ENEMY;
		play->i += 1;
		map[x][y] = SPACE;
	}
}

void	put_enemy(char **map, t_game *play)
{
	play->i = 0;
	while (map[play->i])
	{
		play->j = 0;
		while (map[play->i][play->j])
		{
			if (map[play->i][play->j] == ENEMY)
				put_check(play, map, play->i, play->j);
			play->j++;
		}
		play->i++;
	}
}
