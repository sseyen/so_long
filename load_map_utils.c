/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:19:17 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/03 23:20:01 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linelen(char *file)
{
	int		fd;
	char	*line;
	int		len;

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

int	ft_count_lines(char *file, int len)
{
	int		fd;
	char	*line;
	int		count;

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

char	**ft_freemap(char **map, int count_lines)
{
	int	i;

	i = 0;
	while (i < count_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
