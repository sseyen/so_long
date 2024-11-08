/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:00:04 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 23:14:59 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_point	find_char(char **map, char c)
{
	t_point	point;
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				point.x = j;
				point.y = i;
				return (point);
			}
			j++;
		}
		i++;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

size_t	get_lines_count(char *file)
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
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (0);
	return (count);
}

size_t	get_line_len(char *file)
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
	if (close(fd) == -1)
		return (0);
	return (len);
}
