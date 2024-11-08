/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:27:04 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 23:19:19 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct map
{
	char		**map;
	t_point		player;
	t_point		exit;
	t_point		*collect;
	size_t		collect_count;
	size_t		lines;
	size_t		len;
}	t_map;

// load_map.c + load_map_utils.c
t_map	*load_map(char *file);
size_t	get_lines_count(char *file);
size_t	get_line_len(char *file);
t_point	find_char(char **map, char c);

// validate_map.c
int		validate_map(t_map *map);

// utils
size_t	count_chars(char **map, char c);
void	free_map(t_map *map);
t_map	*copy_map(t_map *map);


#endif