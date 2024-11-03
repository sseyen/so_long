/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:47:05 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/03 23:18:55 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_allocmap(int count_lines, int linelen)
{
	char	**map;
	int		i;

	if (count_lines < 3 && linelen < 5)
		return (NULL);
	else if (count_lines < 5 && linelen < 3)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (count_lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < count_lines)
	{
		map[i] = (char *)malloc(sizeof(char) * (linelen + 1));
		if (!map[i])
		{
			while (i--)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

static char	**ft_writemap(char **map, char *file, int linelen, int count_lines)
{
	int		fd;
	char	*line;
	int		i;

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
	close(fd);
	return (map);
}

char	**ft_load_map(char *file)
{
	char	**map;
	int		linelen;
	int		count_lines;

	linelen = ft_linelen(file);
	count_lines = ft_count_lines(file, linelen);
	map = ft_allocmap(count_lines, linelen);
	if (!map)
		return (NULL);
	map = ft_writemap(map, file, linelen, count_lines);
	return (map);
}
