/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:26:48 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/29 13:04:59 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win_img(t_data **data)
{
	(*data)->mlx = mlx_init();
	(*data)->mlx_window = mlx_new_window((*data)->mlx, 1920, 1000, "Hello World");
	(*data)->img->img = mlx_new_image((*data)->mlx, 1920, 1000);
	(*data)->img->addr = mlx_get_data_addr((*data)->img->img,
		&(*data)->img->bit_per_pixel,
		&(*data)->img->line_height,
		&(*data)->img->endian);
}

int	main(int argn, char **args)
{
	t_data *data;

	if (argn != 2)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data)
		data->img = (t_image_data *)malloc(sizeof(t_image_data));
	if (!data || !data->img)
		return (1);
	init_win_img(&data);
	functions_win(&data);
	events();
	draw(args[1]);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img->img, 0, 0);
	mlx_loop(data->mlx);
}

/* cc main.c -Lminilibx-linux -lmlx -lXext -lX11
COmando basico de compilación */

/* for (int y = 0; y < 1000; y++)
    {
        for (int x = 0; x < 1920; x++)
		{
			if (x % 50 == 0)
			put_pixel(data->img, x, y, 0xFF1110);
			if (y % 50 == 0)
			put_pixel(data->img, x, y, 0xFF1110);

		}
    } */