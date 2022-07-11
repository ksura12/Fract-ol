/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/11 17:42:17 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;
	
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int	*)dst = color;
}

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green <<8 | blue);
// }

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_image(data->mlx_ptr, data->img);
		free(data->img);
		free(data->mlx_ptr);
		exit (0);
	}
	return (0);
}

int render_backr(t_data *data)
{
	int c;
	int d;
	
	// if (data->win_ptr != NULL)
	// {
		// data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		// data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		c = 0;
		while(c++ < WIDTH)
		{
			d = 0;
			while( d++ < HEIGHT - 1)
			{
				my_mlx_pixel_put(data, c, d , 0x00FF00FF);
			}
		}
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	// mlx_destroy_image(data->mlx_ptr, data->img);
	// }
	return (0);
}

int render(t_data *data)
{
	int c;
	int d;
	
	// if (data->win_ptr != NULL)
	// {
		// data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		// data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		c = 0;
		while(c++ < 100)
		{
			d = 0;
			while( d++ < 100)
			{
				my_mlx_pixel_put(data, c, d , 0x00FFAAFF);
			}
		}
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	// mlx_destroy_image(data->mlx_ptr, data->img);
	// }
	return (0);
}

int put_img(t_data *data)
{
	int x;
	int y;
		if (data->win_ptr != NULL)
	{
			data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
			data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
			render_backr(data);
			render(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
			mlx_destroy_image(data->mlx_ptr, data->img);

		
		// free(data->img);
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_data	img;
	// char	*relative_path = "./mandelbrot.xpm";
	// int		img_width = 354;
	// int		img_height = 337;

	if (argc >= 1)
	{
		img.mlx_ptr = mlx_init();
		if (img.mlx_ptr == NULL)
			return (MLX_ERROR);
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "First Window");
		if (img.win_ptr == NULL)
		{
			free(img.win_ptr);
			return (MLX_ERROR);
		}

		// img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		
		// hooks //
		mlx_loop_hook(img.mlx_ptr, &put_img, &img);
		// mlx_hook(img.win_ptr, KeyPress, KeypressMask, &handle_keypress, &img);
		mlx_hook(img.win_ptr, 2, 0, handle_keypress, &img);
		
		mlx_loop(img.mlx_ptr);
		
		// destroing window, exit code if
		if (img.win_ptr == NULL)
		{
			free(img.mlx_ptr);
			exit (0);
		}
		
		
		
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		
		// img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
		// ft_printf("%i\n", img.img);
		ft_printf("%s\n", argv[1]);						
		// mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.img, 0, 0);
		
		return (0);
	}
}
