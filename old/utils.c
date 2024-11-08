/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:56:43 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 20:20:15 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_writecoord(t_map *map)
{
	int	i;
	int	j;
	int	k;

	map->collect_count = ft_count(map->map, 'C');
	map->collect = (t_point *)malloc(sizeof(t_point) * map->collect_count);
	i = -1;
	k = 0;
	while (map->map[++i])
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
	}
	if (!map->collect)
		return ;
	map->exit = ft_find(map->map, 'E');
	map->player = ft_find(map->map, 'P');
}

t_point	ft_find(char **map, char c)
{
	t_point	coord;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coord.x = j;
				coord.y = i;
				return (coord);
			}
			j++;
		}
		i++;
	}
	coord.x = -1;
	coord.y = -1;
	return (coord);
}

char	**ft_copymap(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	**ft_freemap(t_map *map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map->collect);
	free(map);
	return (NULL);
}
