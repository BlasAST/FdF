/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/29 13:57:50 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	put_pixel(t_image_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_height + x * (img->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(char *file)
{
	char ***lines;
	char *line;

	read_file(file);
	
}