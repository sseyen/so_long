/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:27:04 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/16 01:33:49 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# define BLOCK_SIZE 16
# define EVENT_CLOSE 17
# ifndef ESC_KEY
#  define ESC_KEY 53
# endif
# ifndef KEY_UP
#  define KEY_UP 126
# endif
# ifndef KEY_DOWN
#  define KEY_DOWN 125
# endif
# ifndef KEY_LEFT
#  define KEY_LEFT 123
# endif
# ifndef KEY_RIGHT
#  define KEY_RIGHT 124
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char		**map;
	t_point		player;
	t_point		exit;
	size_t		collect_count;
	size_t		height;
	size_t		width;
}	t_map;

typedef struct s_data
{
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_exit;
	void	*img_collect;
	void	*img_floor;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		move;
}	t_data;

// load_map.c + load_map_utils.c
t_map	*load_map(char *file);
size_t	get_height(char *file);
size_t	get_width(char *file);
t_point	find_char(char **map, char c);

// validate_map.c
int		validate_map(t_map *map);

// utils
size_t	count_chars(char **map, char c);
void	free_map(t_map *map);
t_map	*copy_map(t_map *map);
int		exit_mlx(t_data *data);

// run_mlx.c
void	run_mlx(t_map *map);

#endif