/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 15:22:40 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_point(t_point p, t_data *dt)
{
	double	x_temp;
	double	y_temp;
	double	z_divisor;

	x_temp = p.x;
	y_temp = p.y;
	if (dt->max_z >= 50)
		z_divisor = 25;
	else if (dt->max_z >= 20)
		z_divisor = 15;
	else if (dt->max_z >= 10)
		z_divisor = 10;
	else
		z_divisor = 2.5;
	p.x = (x_temp - y_temp) * cos(dt->angle) * dt->zoom;
	p.y = (x_temp + y_temp) * sin(dt->angle) * dt->zoom;
	p.y -= (p.z * dt->zoom) / z_divisor;
	p.x += dt->offset_x;
	p.y += dt->offset_y;
	return (p);
}

void	make_draw(t_point next, t_point current, t_data *dt)
{
	next = project_point(next, dt);
	draw_line(dt, current, next);
}

void	draw_map(t_data *dt)
{
	int		x;
	int		y;
	t_point	current;

	y = 0;
	while (y < dt->map_size_h)
	{
		x = 0;
		while (x < dt->map_size_w)
		{
			current = dt->map[y][x];
			current = project_point(current, dt);
			if (x < dt->map_size_w - 1)
				make_draw(dt->map[y][x + 1], current, dt);
			if (y < dt->map_size_h - 1)
				make_draw(dt->map[y + 1][x], current, dt);
			x++;
		}
		y++;
	}
}

int	points_paint(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n'
			&& (i == 0 || str[i - 1] == ' '))
			size++;
		i++;
	}
	return (size);
}

int	points_paint_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}
