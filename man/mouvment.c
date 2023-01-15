/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:44:32 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/15 12:13:44 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_map(void)
{
	write(1, "Error\nyour map is empty!", 24);
	exit(1);
}

static void	final_step(char **map, t_demensions p_play, t_game *play)
{
	if (map[p_play.vertical][p_play.horizontal] == EXIT)
	{
		free_2_map(play->map);
		free_exit_and_all(play);
		write(1, "you win!\n", 10);
		exit(0);
	}
}

static void	check_mov(int key, t_game *play)
{
	if (key == 53)
		end_win(play);
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

int	play_game(int key, t_game *play)
{
	check_mov(key, play);
	if (play->map[play->p_play.vertical][play->p_play.horizontal] != WALL)
	{
		play->move++;
		ft_putnbr(play->move);
		write(1, "\n", 1);
		put_move(play->map, play);
	}
	start_map(play);
	return (0);
}
