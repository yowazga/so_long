/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:44:32 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/15 12:09:49 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	final_step(char **map, t_demensions p_play, t_game *play)
{
	if (map[p_play.vertical][p_play.horizontal] == EXIT)
	{
		free_2_map(play->map);
		free_enemy(play);
		write(1, "you won!", 8);
		exit(0);
	}
}

static void	check_mov(int key, t_game *play)
{
	if (key == 13 || key == 126)
	{
		play->p_play.vertical -= 1;
		play->direction = PLAYER_UP;
	}
	else if (key == 1 || key == 125)
	{
		play->p_play.vertical += 1;
		play->direction = PLAYER_DOWN;
	}
	else if (key == 2 || key == 124)
	{
		play->p_play.horizontal += 1;
		play->direction = PLAYER_RIGHT;
	}
	else if (key == 0 || key == 123)
	{
		play->p_play.horizontal -= 1;
		play->direction = PLAYER_LEFT;
	}
}

static void	put_move(char **map, t_game *play)
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
				map[i][j] = SPACE;
			if (i == play->p_play.vertical && j == play->p_play.horizontal)
				map[i][j] = PLAYER;
			if (map[play->p_door.vertical][play->p_door.horizontal]
				!= map[play->p_play.vertical][play->p_play.horizontal] &&
					play->collect != 0)
				map[play->p_door.vertical][play->p_door.horizontal] = DOOR;
			else if (map[i][j] == DOOR && play->collect == 0)
				map[i][j] = EXIT;
			final_step(play->map, play->p_play, play);
			j++;
		}
		i++;
	}
}

void	exit_all(t_game *play)
{
	free_2_map(play->map);
	free_enemy(play);
	exit(0);
}

int	play_game(int key, t_game *play)
{
	if (key == 53)
		exit_all(play);
	check_mov(key, play);
	if (play->map[play->p_play.vertical][play->p_play.horizontal] == ENEMY)
	{
		write(1, "you lose!", 9);
		exit_all(play);
	}
	else if (play->map[play->p_play.vertical][play->p_play.horizontal] != WALL)
	{
		if (key == 126 || key == 13 || key == 1 || key == 125
			|| key == 2 || key == 124 || key == 0 || key == 123)
			play->move++;
		put_move(play->map, play);
		put_enemy(play->map, play);
	}
	start_map(play);
	play->str = ft_itoa(play->move);
	mlx_put_image_to_window(play->mlx, play->win, play->content.table,
		(play->d_win.horizontal * 80) / 2, 0);
	mlx_string_put(play->mlx, play->win, (play->d_win.horizontal * 80) / 2 + 30,
		30, 0xffffff, play->str);
	free(play->str);
	return (0);
}
