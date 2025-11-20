/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 00:57:07 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
		clean_and_exit(data, 0, 0, NULL);
	return (0);
}

static int	close_button(t_data *data)
{
	clean_and_exit(data, 0, 0, NULL);
	return (0);
}

static int	render_frame(t_data *dt)
{
	clear_image(dt);
	draw_map(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->i_d.img, 0, 0);
	return (0);
}

void	functions_win(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_button, data);
	mlx_loop_hook(data->mlx_ptr, render_frame, data);
}

void	put_zoom(t_data *dt)
{
	int	max_dim;

	if (dt->map_size_w > dt->map_size_h)
		max_dim = dt->map_size_w;
	else
		max_dim = dt->map_size_h;
	if (max_dim > 0)
		dt->zoom = (dt->map_size_w_view * 0.5) / max_dim;
	else
		dt->zoom = 1;
	if (dt->zoom < 1)
		dt->zoom = +dt->zoom;
}
