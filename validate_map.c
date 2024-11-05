/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:46:23 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/05 19:53:48 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_way(char **map, t_point point, int collectables)
{
	int					i;
	int					j;
	static t_valid_way	way = {0, 0};

	i = point.y;
	j = point.x;
	if (map[i][j] == '1' || map[i][j] == 'V')
		return (0);
	if (map[i][j] == 'E')
		way.exit = 1;
	if (map[i][j] == 'C')
		way.collect++;
	if (way.exit && way.collect == collectables)
		return (1);
	map[i][j] = 'V';
	if (ft_validate_way(map, (t_point){i + 1, j}, collectables) || \
		ft_validate_way(map, (t_point){i - 1, j}, collectables) || \
		ft_validate_way(map, (t_point){i, j + 1}, collectables) || \
		ft_validate_way(map, (t_point){i, j - 1}, collectables))
		return (1);
	return (0);
}

int	ft_validate_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || !map[i + 1])
			{
				if (map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == ft_strlen(map[i]) - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_count(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
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

int	ft_validate_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_validate_map(char **map)
{
	t_point	player;
	char	**copy;
	int		collectables;

	if (!ft_validate_chars(map))
		return (0);
	if (ft_count(map, 'P') != 1 || ft_count(map, 'E') != 1)
		return (0);
	collectables = ft_count(map, 'C');
	if (collectables < 1)
		return (0);
	if (!ft_validate_borders(map))
		return (0);
	copy = ft_copymap(map);
	if (!copy)
		return (0);
	player = ft_find(map, 'P');
	if (!ft_validate_way(copy, player, collectables))
	{
		free(copy);
		return (0);
	}
	free(copy);
	return (1);
}
