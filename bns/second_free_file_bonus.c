/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_free_file_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:07:58 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/08 19:58:09 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_wall(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.wall);
	free_play_up(play);
}

void	free_collect(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.collect);
	free_wall(play);
}

void	free_space(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.space);
	free_wall(play);
}

void	free_door(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.door);
	free_space(play);
}

void	free_exit(t_game *play)
{
	mlx_destroy_image(play->mlx, play->content.exit);
	free_door(play);
}
