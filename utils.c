/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:56:43 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/04 16:56:57 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
