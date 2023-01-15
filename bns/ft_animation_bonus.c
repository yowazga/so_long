/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:35:16 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/08 19:57:47 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	play_left(t_game *play, int i, int j, int x)
{
	if (x < 10)
	{
		mlx_put_image_to_window(play->mlx, play->win, play->content.space,
			j * 80, i * 80);
		if (play->map[play->p_door.vertical][play->p_door.horizontal]
			== play->map[play->p_play.vertical][play->p_play.horizontal])
			mlx_put_image_to_window(play->mlx, play->win, play->content.door,
				j * 80, i * 80);
		mlx_put_image_to_window(play->mlx, play->win,
			play->content.player.up_down, j * 80, i * 80);
	}
	if (x >= 10 && x < 20)
	{
		mlx_put_image_to_window(play->mlx, play->win,
			play->content.space, j * 80, i * 80);
		if (play->map[play->p_door.vertical][play->p_door.horizontal]
			== play->map[play->p_play.vertical][play->p_play.horizontal])
			mlx_put_image_to_window(play->mlx, play->win, play->content.door,
				j * 80, i * 80);
		mlx_put_image_to_window(play->mlx, play->win,
			play->content.player.left, j * 80, i * 80);
	}
}

static void	play_right(t_game *play, int i, int j, int y)
{
	if (y < 10)
	{
		mlx_put_image_to_window(play->mlx, play->win, play->content.space,
			j * 80, i * 80);
		if (play->map[play->p_door.vertical][play->p_door.horizontal]
			== play->map[play->p_play.vertical][play->p_play.horizontal])
			mlx_put_image_to_window(play->mlx, play->win, play->content.door,
				j * 80, i * 80);
		mlx_put_image_to_window(play->mlx, play->win,
			play->content.player.right, j * 80, i * 80);
	}
	if (y >= 10 && y < 20)
	{
		mlx_put_image_to_window(play->mlx, play->win,
			play->content.space, j * 80, i * 80);
		if (play->map[play->p_door.vertical][play->p_door.horizontal]
			== play->map[play->p_play.vertical][play->p_play.horizontal])
			mlx_put_image_to_window(play->mlx, play->win, play->content.door,
				j * 80, i * 80);
		mlx_put_image_to_window(play->mlx, play->win,
			play->content.player.up, j * 80, i * 80);
	}
}

int	animation(t_game *play)
{
	static int	x;
	static int	y;
	int			i;
	int			j;

	i = play->p_play.vertical;
	j = play->p_play.horizontal;
	if (play->direction == PLAYER_DOWN || play->direction == PLAYER_LEFT)
		play_left(play, i, j, x);
	else if (play->direction == PLAYER_UP || play->direction == PLAYER_RIGHT)
		play_right(play, i, j, y);
	if (x > 20)
		x = 0;
	if (y > 20)
		y = 0;
	x++;
	y++;
	return (0);
}
