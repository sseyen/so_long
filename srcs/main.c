/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:30:23 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/08 23:08:54 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_input(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 1);
		return (0);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 1);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (!validate_input(argc, argv))
		return (1);
	map = load_map(argv[1]);
	if (!map)
		return (1);
	if (!validate_map(map))
	{
		free_map(map);
		ft_putstr_fd("Error\nInvalid map\n", 1);
		return (1);
	}
	free_map(map);
	return (0);
}
