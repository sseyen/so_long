/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:29:45 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 21:31:41 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->lines)
		free(map->map[i++]);
	free(map->map);
	free(map->collect);
	free(map);
}
