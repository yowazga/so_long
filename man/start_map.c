/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:02:17 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/09 14:12:57 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *play, char *content, int i, int j)
{
	if ((play->map[play->p_play.vertical][play->p_play.horizontal]
		== play->map[play->p_door.vertical][play->p_door.horizontal]) &&
		(play->map[play->p_play.vertical][play->p_play.horizontal] == PLAYER))
	{
		mlx_put_image_to_window(play->mlx, play->win, play->content.space,
			play->p_win.horizontal, play->p_win.vertical);
		if (play->map[i][j] == PLAYER)
			mlx_put_image_to_window(play->mlx, play->win, play->content.door,
				play->p_win.horizontal, play->p_win.vertical);
		mlx_put_image_to_window(play->mlx, play->win, content,
			play->p_win.horizontal, play->p_win.vertical);
	}
	else
	{
		mlx_put_image_to_window(play->mlx, play->win, play->content.space,
			play->p_win.horizontal, play->p_win.vertical);
		mlx_put_image_to_window(play->mlx, play->win, content,
			play->p_win.horizontal, play->p_win.vertical);
	}
}

static void	put_player(t_game *play, int i, int j)
{
	if (play->direction == PLAYER_UP)
		put_image(play, play->content.player.up, i, j);
	if (play->direction == PLAYER_DOWN)
		put_image(play, play->content.player.up_down, i, j);
	if (play->direction == PLAYER_LEFT)
		put_image(play, play->content.player.left, i, j);
	if (play->direction == PLAYER_RIGHT)
		put_image(play, play->content.player.right, i, j);
}

static void	put_map(t_game *play, char colom, int i, int j)
{
	if (colom == WALL)
		put_image(play, play->content.wall, i, j);
	else if (colom == SPACE)
		put_image(play, play->content.space, i, j);
	else if (colom == COIN)
	{
		put_image(play, play->content.collect, i, j);
		play->collect++;
	}
	else if (colom == DOOR)
	{
		put_image(play, play->content.door, i, j);
		play->p_door.vertical = i;
		play->p_door.horizontal = j;
	}
	else if (colom == PLAYER)
	{
		play->p_play.vertical = i;
		play->p_play.horizontal = j;
		put_player(play, i, j);
	}
	else if (colom == EXIT)
		put_image(play, play->content.exit, i, j);
}

void	start_map(t_game *play)
{
	int	i;
	int	j;

	i = 0;
	play->collect = 0;
	play->p_win.vertical = 0;
	while (play->map[i])
	{
		j = 0;
		play->p_win.horizontal = 0;
		while (play->map[i][j])
		{
			put_map(play, play->map[i][j], i, j);
			j++;
			play->p_win.horizontal += 80;
		}
			play->p_win.vertical += 80;
			i++;
	}
}
