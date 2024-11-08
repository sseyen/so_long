/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:20:21 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 20:18:41 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_valid_way
{
	int	collect;
	int	exit;
}	t_valid_way;

typedef struct s_map
{
	char		**map;
	t_point		player;
	t_point		exit;
	t_point		*collect;
	size_t		collect_count;
	size_t		lines;
	size_t		len;
}	t_map;

t_map	*ft_load_map(char *file);
char	**ft_freemap(t_map *map);
char	**ft_copymap(char **map);
int		ft_validate_map(char **map);
size_t	ft_count(char **map, char c);
t_point	ft_find(char **map, char c);
void	ft_writecoords(t_map *map);

#endif