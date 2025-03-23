/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_content_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:01:14 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/09 13:16:05 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	alloc_player_1(t_game *play)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	play->content.player.up_down
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/play_left1.xpm", &a, &b);
	if (!play->content.player.up_down)
	{
		free_mlx(play);
		exit(1);
	}	
	play->content.player.left
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/play_left2.xpm", &a, &b);
	if (!play->content.player.left)
	{
		free_play_down(play);
		exit(1);
	}
}

static void	alloc_player_2(t_game *play)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	play->content.player.right
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/play_rght1.xpm", &a, &b);
	if (!play->content.player.right)
	{
		free_play_left(play);
		exit(1);
	}
	play->content.player.up
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/play_right2.xpm", &a, &b);
	if (!play->content.player.up)
	{
		free_play_right(play);
		exit(1);
	}
}

static void	alloc_0(t_game *play, int a, int b)
{
	play->content.wall
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/wall.xpm", &a, &b);
	if (!play->content.wall)
	{
		free_play_up(play);
		exit(1);
	}
	play->content.collect
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/collect_b.xpm", &a, &b);
	if (!play->content.collect)
	{
		free_wall(play);
		exit(1);
	}
}

static void	alloc_1(t_game *play, int a, int b)
{
		play->content.space
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/space.xpm", &a, &b);
	if (!play->content.space)
	{
		free_collect(play);
		exit(1);
	}
	play->content.table
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/table.xpm", &a, &b);
	if (!play->content.table)
	{
		free_exit(play);
		exit(1);
	}
	play->content.enemy
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/enemy.xpm", &a, &b);
	if (!play->content.enemy)
	{
		free_table(play);
		exit(1);
	}
}

void	alloc_content(t_game *play)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	alloc_player_1(play);
	alloc_player_2(play);
	alloc_0(play, a, b);
	alloc_1(play, a, b);
	play->content.door
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/door.xpm", &a, &b);
	if (!play->content.door)
	{
		free_space(play);
		exit(1);
	}
	play->content.exit
		= mlx_xpm_file_to_image(play->mlx, "./bns/xpm/exit.xpm", &a, &b);
	if (!play->content.exit)
	{
		free_door(play);
		exit(1);
	}
}
