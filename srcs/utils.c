/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:29:45 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/26 14:26:49 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_image(data->mlx, data->img_exit);
	mlx_destroy_image(data->mlx, data->img_collect);
	mlx_destroy_image(data->mlx, data->img_floor);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	free_map(data->map);
	free(data);
	exit(0);
	return (0);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

static char	**copy_map_lines(t_map *map_copy, t_map *map)
{
	size_t	i;

	map_copy->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map_copy->map)
		return (NULL);
	i = 0;
	while (i < map->height)
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
	map_copy->height = map->height;
	map_copy->width = map->width;
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
