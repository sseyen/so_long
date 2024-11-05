/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:47:05 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/05 20:36:00 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_linelen(char *file)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	free(line);
	return (len);
}

static size_t	ft_count_lines(char *file, size_t len)
{
	int		fd;
	char	*line;
	size_t	count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) != len || line[0] != '1' || line[len - 1] != '1')
		{
			free(line);
			close(fd);
			return (0);
		}
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**ft_allocmap(size_t count_lines, size_t linelen)
{
	char	**map;
	size_t		i;

	map = (char **)malloc(sizeof(char *) * (count_lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < count_lines)
	{
		map[i] = (char *)malloc(sizeof(char) * (linelen + 1));
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

static char	**ft_writemap(char **map, char *file)
{
	int		fd;
	char	*line;
	size_t		i;

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
	size_t	linelen;
	size_t	count_lines;

	linelen = ft_linelen(file);
	count_lines = ft_count_lines(file, linelen);
	if ((count_lines < 3 || linelen < 5) && (count_lines < 5 || linelen < 3))
		return (NULL);
	map = ft_allocmap(count_lines, linelen);
	if (!map)
		return (NULL);
	map = ft_writemap(map, file);
	return (map);
}
