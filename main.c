#include "mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

#define ESC_KEY 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

typedef struct s_data {
    void	*mlx;
    void	*win;
    void	*img;
    void	*bg_img;
    int		img_width;
    int		img_height;
    int		bg_width;
    int		bg_height;
    int		x;
    int		y;
    int		prev_x;
    int		prev_y;
}	t_data;

void	render_to_buffer(t_data *data)
{
    // Draw the background
    mlx_put_image_to_window(data->mlx, data->win, data->bg_img, 0, 0);

    // Draw the player at its current position
    mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
}

// Handle key presses to move the image
int	handle_keypress(int keycode, t_data *data)
{
    data->prev_x = data->x;
    data->prev_y = data->y;

    if (keycode == ESC_KEY)
    {
        mlx_destroy_image(data->mlx, data->img);
        mlx_destroy_image(data->mlx, data->bg_img);
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == KEY_UP)
        data->y -= 10; // Move up
    else if (keycode == KEY_DOWN)
        data->y += 10; // Move down
    else if (keycode == KEY_LEFT)
        data->x -= 10; // Move left
    else if (keycode == KEY_RIGHT)
        data->x += 10; // Move right

    // Redraw the background at the previous position
    mlx_put_image_to_window(data->mlx, data->win, data->bg_img, data->prev_x, data->prev_y);

    // Draw the player at its new position
    mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);

    return (0);
}

int	render_next_frame(t_data *data)
{
    // Clear the window
    mlx_clear_window(data->mlx, data->win);

    // Render the background and image to the buffer
    render_to_buffer(data);

    return (0);
}

int	main(void)
{
    t_data	data;

    // Initialize MiniLibX and create a window
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Continuous Render Example");

    // Load images (replace with actual image loading code)
    data.img = mlx_xpm_file_to_image(data.mlx, "textures/player.xpm", &data.img_width, &data.img_height);
    data.bg_img = mlx_xpm_file_to_image(data.mlx, "textures/background.xpm", &data.bg_width, &data.bg_height);

    if (!data.img || !data.bg_img)
    {
        write(2, "Failed to load images\n", 22);
        exit(1);
    }

    // Set initial position for the image
    data.x = 400 - (data.img_width / 2);
    data.y = 300 - (data.img_height / 2);
    data.prev_x = data.x;
    data.prev_y = data.y;

    // Set up key press and render hooks
    mlx_key_hook(data.win, handle_keypress, &data);
    mlx_loop_hook(data.mlx, render_next_frame, &data);

    // Start the main loop
    mlx_loop(data.mlx);

    return (0);
}