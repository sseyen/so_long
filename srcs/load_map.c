/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:37:13 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 21:36:22 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_point	*write_collectables(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	k;

	map->collect_count = count_chars(map->map, 'C');
	map->collect = (t_point *)malloc(sizeof(t_point) * map->collect_count);
	if (!map->collect)
		return (NULL);
	i = 0;
	k = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
			{
				map->collect[k].x = j;
				map->collect[k++].y = i;
			}
			j++;
		}
		i++;
	}
	return (map->collect);
}

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
	while (i < map->lines)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->len + 1));
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
	map->len = get_line_len(file);
	if (!map->len)
		return (NULL);
	map->lines = get_lines_count(file);
	if (!map->lines)
		return (NULL);
	map->map = (char **)malloc(sizeof(char *) * (map->lines + 1));
	if (!map->map)
		return (NULL);
	map->map[map->lines] = NULL;
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
	write_collectables(map);
	map->player = find_char(map->map, 'P');
	map->exit = find_char(map->map, 'E');
	return (map);
}
