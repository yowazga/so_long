/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_free_file_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:39:18 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/08 19:58:46 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_mlx(t_game *play)
{
	mlx_destroy_window(play->mlx, play->win);
	free(play->mlx);
}

void	free_play_down(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.player.up_down);
	free_mlx(play);
}

void	free_play_left(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.player.left);
	free_play_down(play);
}

void	free_play_right(t_game *paly)
{
	mlx_destroy_image(paly->mlx, paly->content.player.right);
	free_play_left(paly);
}

void	free_play_up(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.player.up);
	free_play_right(play);
}
