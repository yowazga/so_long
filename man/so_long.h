/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:02:04 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/15 11:45:53 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"

/*******************************************************************/
/*                         All define                              */
/*******************************************************************/
# define PLAYER_UP 0
# define PLAYER_DOWN 1
# define PLAYER_RIGHT 2
# define PLAYER_LEFT 3 

# define WALL 49
# define COIN 67
# define SPACE 48
# define DOOR 69
# define EXIT 101
# define PLAYER 80

/*******************************************************************/
/*                           the structs                           */
/*******************************************************************/
typedef struct deme
{
	int	horizontal;
	int	vertical;
}t_demensions;

typedef struct players
{
	void	*up_down;
	void	*left;
	void	*right;
	void	*up;
}t_player;

typedef struct CellType
{
	void		*wall;
	void		*collect;
	void		*door;
	void		*space;
	void		*exit;
	t_player	player;
}t_content;

typedef struct so_long
{
	void			*mlx;
	void			*win;
	char			**map;
	int				direction;
	int				collect;
	int				move;
	t_demensions	d_win;
	t_demensions	p_play;
	t_demensions	p_door;
	t_demensions	p_win;
	t_content		content;
}t_game;

/******************************************************************/
/*                       function libft                           */
/******************************************************************/

char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int nb);
char	*ft_strdup(char *s1);

/******************************************************************/
/*                         function so_long                       */
/******************************************************************/

void	check_map(char **map, t_demensions s_window, t_game *play);
void	chack_valid_path(char **map, t_demensions s_win, t_game *play);
void	alloc_content(t_game *play);
void	start_map(t_game *play);
int		play_game(int key, t_game *play);
void	free_2_map(char **str);
void	check_size(t_demensions size, t_game *play);
int		end_win(t_game *play);
void	empty_map(void);

/******************************************************************/
/*                         function for free                      */
/******************************************************************/

void	free_mlx(t_game *play);
void	free_play_down(t_game *play);
void	free_play_left(t_game *play);
void	free_play_right(t_game *paly);
void	free_play_up(t_game *play);
void	free_wall(t_game *play);
void	free_collect(t_game *play);
void	free_space(t_game *play);
void	free_door(t_game *play);
void	free_exit_and_all(t_game *play);

#endif
