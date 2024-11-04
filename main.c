/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:50:46 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/04 16:56:20 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	int		fd;
	char	**map;
	int		i;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 1);
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 1);
		return (1);
	}
	map = ft_load_map(argv[1]);
	if (!map || !ft_validate_map(map))
	{
		ft_free(map);
		ft_putstr_fd("Error\nInvalid map\n", 1);
		return (1);
	}
	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar_fd('\n', 1);
		free(map[i]);
		i++;
	}
	free(map);
}
