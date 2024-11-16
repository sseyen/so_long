/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:37:13 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/15 23:31:39 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**write_map_lines(char *file, char **map)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (close(fd) == -1)
	{
		while (*map)
			free(*map++);
		free(map);
		return (NULL);
	}
	return (map);
}

static char	**allocate_map_lines(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->map[i])
		{
			while (i > 0)
				free(map->map[--i]);
			return (NULL);
		}
		i++;
	}
	return (map->map);
}

static t_map	*write_map(char *file, t_map *map)
{
	map->width = get_width(file);
	if (!map->width)
		return (NULL);
	map->height = get_height(file);
	if (!map->height)
		return (NULL);
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (NULL);
	map->map[map->height] = NULL;
	if (!allocate_map_lines(map))
	{
		free(map->map);
		return (NULL);
	}
	if (!write_map_lines(file, map->map))
	{
		free(map->map);
		return (NULL);
	}
	return (map);
}

t_map	*load_map(char *file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!write_map(file, map))
	{
		free(map);
		return (NULL);
	}
	map->collect_count = count_chars(map->map, 'C');
	map->player = find_char(map->map, 'P');
	map->exit = find_char(map->map, 'E');
	return (map);
}
