/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:29:45 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 23:15:14 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->lines)
		free(map->map[i++]);
	free(map->map);
	free(map->collect);
	free(map);
}

static t_point	*copy_map_collect(t_map *map_copy, t_map *map)
{
	size_t	i;

	map_copy->collect = (t_point *)malloc(sizeof(t_point) * map->collect_count);
	if (!map_copy->collect)
		return (NULL);
	i = 0;
	while (i < map->collect_count)
	{
		map_copy->collect[i] = map->collect[i];
		i++;
	}
	return (map_copy->collect);
}

static char	**copy_map_lines(t_map *map_copy, t_map *map)
{
	size_t	i;

	map_copy->map = (char **)malloc(sizeof(char *) * (map->lines + 1));
	if (!map_copy->map)
		return (NULL);
	i = 0;
	while (i < map->lines)
	{
		map_copy->map[i] = ft_strdup(map->map[i]);
		if (!map_copy->map[i])
		{
			while (i > 0)
				free(map_copy->map[--i]);
			return (NULL);
		}
		i++;
	}
	map_copy->map[i] = NULL;
	return (map_copy->map);
}

t_map	*copy_map(t_map *map)
{
	t_map	*map_copy;

	map_copy = (t_map *)malloc(sizeof(t_map));
	if (!map_copy)
		return (NULL);
	map_copy->map = copy_map_lines(map_copy, map);
	if (!map_copy->map)
	{
		free(map_copy);
		return (NULL);
	}
	map_copy->collect = copy_map_collect(map_copy, map);
	map_copy->lines = map->lines;
	map_copy->len = map->len;
	map_copy->collect_count = map->collect_count;
	map_copy->player = map->player;
	map_copy->exit = map->exit;
	return (map_copy);
}

size_t	count_chars(char **map, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
