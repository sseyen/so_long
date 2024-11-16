/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:54:05 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/16 02:09:30 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move(t_data *data, int x, int y)
{
	if (data->map->map[data->y + y][data->x + x] == '1')
		return ;
	if (data->map->map[data->y + y][data->x + x] == 'C')
	{
		data->map->map[data->y + y][data->x + x] = '0';
		data->map->collect_count--;
	}
	ft_putnbr_fd(++data->move, 1);
	ft_putchar_fd('\n', 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img_floor, \
	data->prev_x * BLOCK_SIZE, data->prev_y * BLOCK_SIZE);
	if (data->x == data->map->exit.x && data->y == data->map->exit.y)
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit, \
		data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	data->x += x;
	data->y += y;
	mlx_put_image_to_window(data->mlx, data->win, data->img_player, \
	data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	if (data->map->map[data->y][data->x] == 'E')
		if (data->map->collect_count == 0)
			exit_mlx(data);
}

static int	handle_keypress(int keycode, t_data *data)
{
	data->prev_x = data->x;
	data->prev_y = data->y;
	if (keycode == ESC_KEY)
		exit_mlx(data);
	else if (keycode == KEY_UP)
		move(data, 0, -1);
	else if (keycode == KEY_DOWN)
		move(data, 0, 1);
	else if (keycode == KEY_LEFT)
		move(data, -1, 0);
	else if (keycode == KEY_RIGHT)
		move(data, 1, 0);
	return (0);
}

static void	render_to_buffer(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img_wall, x * BLOCK_SIZE, y * BLOCK_SIZE);
			else if (data->map->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img_exit, x * BLOCK_SIZE, y * BLOCK_SIZE);
			else if (data->map->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img_collect, x * BLOCK_SIZE, y * BLOCK_SIZE);
			else
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img_floor, x * BLOCK_SIZE, y * BLOCK_SIZE);
			x++;
		}
		y++;
	}
}

static t_data	*init_data(t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = map;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, map->width * BLOCK_SIZE, \
		map->height * BLOCK_SIZE, "so_long");
	data->img_player = mlx_xpm_file_to_image(data->mlx, \
		"textures/player.xpm", &data->img_width, &data->img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, \
		"textures/wall.xpm", &data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, \
		"textures/exit.xpm", &data->img_width, &data->img_height);
	data->img_collect = mlx_xpm_file_to_image(data->mlx, \
		"textures/collect.xpm", &data->img_width, &data->img_height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, \
		"textures/floor.xpm", &data->img_width, &data->img_height);
	data->x = map->player.x;
	data->y = map->player.y;
	data->prev_x = data->x;
	data->prev_y = data->y;
	return (data);
}

void	run_mlx(t_map *map)
{
	t_data	*data;

	data = init_data(map);
	render_to_buffer(data);
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img_player, data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	mlx_key_hook(data->win, &handle_keypress, data);
	mlx_hook(data->win, EVENT_CLOSE, 0, &exit_mlx, data);
	mlx_loop(data->mlx);
}
