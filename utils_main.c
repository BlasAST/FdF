/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:14:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 14:26:42 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_ini(t_data *df)
{
	df->mlx_ptr = mlx_init();
	if (!df->mlx_ptr)
	{
		free(df);
		error_ex("Error de interfaz grafica\n", 1);
	}
	df->win_ptr = mlx_new_window(df->mlx_ptr, df->map_size_w_view,
			df->map_size_h_view, "Salu2");
	df->i_d.img = mlx_new_image(df->mlx_ptr, df->map_size_w_view,
			df->map_size_h_view);
	df->i_d.addr = mlx_get_data_addr(df->i_d.img, &df->i_d.bit_per_pixel,
			&df->i_d.line_length, &df->i_d.endian);
}

void	init_projection(t_data *dt)
{
	double	center_shift;

	max_size_z(dt);
	dt->map_size_h_view = 800;
	dt->map_size_w_view = 800;
	dt->angle = 0.523599;
	put_zoom(dt);
	center_shift = (dt->map_size_w - dt->map_size_h) * dt->zoom * \
	cos(dt->angle) / 2.0;
	dt->offset_x = (dt->map_size_w_view / 2.0) - center_shift;
	dt->offset_y = (dt->map_size_h_view / 2.0) - \
	((dt->map_size_w + dt->map_size_h) * dt->zoom * sin(dt->angle)) / 2.0;
}

void	finish_fdf(t_data *df)
{
	mlx_put_image_to_window(df->mlx_ptr, df->win_ptr, df->i_d.img, 0, 0);
}
