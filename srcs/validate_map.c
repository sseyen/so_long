/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:58:02 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/16 00:37:30 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	validate_way(t_map *map, t_point point)
{
	size_t			i;
	size_t			j;
	static size_t	exit = 0;
	static size_t	collect_count = 0;

	i = point.y;
	j = point.x;
	if (map->map[i][j] == '1' || map->map[i][j] == 'V')
		return (0);
	if (map->map[i][j] == 'E')
		exit = 1;
	if (map->map[i][j] == 'C')
		collect_count++;
	if (exit && collect_count == map->collect_count)
		return (1);
	map->map[i][j] = 'V';
	if (validate_way(map, (t_point){i + 1, j}) || \
		validate_way(map, (t_point){i - 1, j}) || \
		validate_way(map, (t_point){i, j + 1}) || \
		validate_way(map, (t_point){i, j - 1}))
		return (1);
	return (0);
}

static int	validate_borders(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 || !map->map[i + 1])
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == ft_strlen(map->map[i]) - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_chars(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_width(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	t_map	*map_copy;

	if ((map->height < 3 && map->width < 5) \
		|| (map->height < 5 && map->width < 3))
		return (0);
	if (map->player.x == -1 || map->exit.x == -1 || map->collect_count < 1)
		return (0);
	if (count_chars(map->map, 'P') != 1 || count_chars(map->map, 'E') != 1)
		return (0);
	if (!validate_width(map) || !validate_chars(map) || !validate_borders(map))
		return (0);
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	if (!validate_way(map_copy, map->player))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
