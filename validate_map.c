/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:46:23 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/04 16:55:58 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_validate_map(char **map)
{
	if (!ft_validate_chars(map))
		return (0);
	if (ft_count(map, 'p') != 1 || ft_count(map, 'e') != 1)
		return (0);
	if (ft_counr(map, 'c' < 1))
		return (0);
	if (!ft_validate_borders(map))
		return (0);
	if (!ft_validate_way(map))
		return (0);
	return (1);
}
