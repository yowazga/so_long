/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:54:22 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/12 18:04:21 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	end_win(t_game *play)
{
	exit_all(play);
	return (0);
}

static void	check_name(char *name_map)
{
	while (*name_map && ft_strcmp(name_map, ".ber"))
		name_map++;
	if (!*name_map)
	{
		write(1, "error !\nchek name file map", 27);
		exit (1);
	}
}

static char	**read_map(char *path_map, char **th_map, t_demensions *s_window)
{
	char	*get_line;
	char	*o_line;
	int		fd;

	fd = open(path_map, O_RDONLY);
	get_line = get_next_line(fd);
	if (!get_line)
	{
		write(1, "Error\nyour map is empty!", 24);
		exit(1);
	}
	s_window->horizontal = ft_strlen_2(get_line) - 1;
	s_window->vertical = 1;
	o_line = get_next_line(fd);
	while (o_line)
	{
		s_window->vertical++;
		get_line = ft_strjoin_2(get_line, o_line);
		free(o_line);
		o_line = get_next_line(fd);
	}
	th_map = ft_split(get_line, '\n');
	free(get_line);
	close(fd);
	return (th_map);
}

static void	initialisation(char *path_map, t_game *play)
{
	check_name(path_map);
	play->map = read_map(path_map, play->map, &play->d_win);
	check_size(play->d_win, play);
	check_map(play->map, play->d_win, play);
	play->mlx = mlx_init();
	if (!play->mlx)
	{
		free_2_map(play->map);
		exit(1);
	}
	play->win = mlx_new_window(play->mlx, play->d_win.horizontal * 80,
			play->d_win.vertical * 80, "yo_wazga");
	if (!play->win)
	{
		free(play->mlx);
		free_2_map(play->map);
		exit(1);
	}
	mlx_hook(play->win, 17, 0, end_win, play);
	play->direction = PLAYER_RIGHT;
	alloc_content(play);
	play->move = 0;
	start_map(play);
}

int	main(int ac, char **av)
{
	t_game	play;

	if (ac != 2)
	{
		write(1, "Error\nenter a valid map", 23);
		exit(0);
	}
	initialisation(av[1], &play);
	mlx_hook(play.win, 2, 0, play_game, &play);
	mlx_loop_hook(play.mlx, animation, &play);
	mlx_loop(play.mlx);
}
