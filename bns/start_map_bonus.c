/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:02:17 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/08 19:58:17 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_table(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.table);
	free_exit(play);
}

void	free_enemy(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.enemy);
	free_table(play);
}

static void	put_image(t_game *play, char *content)
{
	mlx_put_image_to_window(play->mlx, play->win, play->content.space,
		play->p_win.horizontal, play->p_win.vertical);
	mlx_put_image_to_window(play->mlx, play->win, content,
		play->p_win.horizontal, play->p_win.vertical);
}

static void	put_map(t_game *play, char colom, int i, int j)
{
	if (colom == WALL)
		put_image(play, play->content.wall);
	else if (colom == SPACE)
		put_image(play, play->content.space);
	else if (colom == COIN)
	{
		put_image(play, play->content.collect);
		play->collect++;
	}
	else if (colom == DOOR)
	{
		put_image(play, play->content.door);
		play->p_door.vertical = i;
		play->p_door.horizontal = j;
	}
	else if (colom == PLAYER)
	{
		play->p_play.vertical = i;
		play->p_play.horizontal = j;
		animation(play);
	}
	else if (colom == EXIT)
		put_image(play, play->content.exit);
	else if (colom == ENEMY)
		put_image(play, play->content.enemy);
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
