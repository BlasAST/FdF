/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:10:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/29 13:14:58 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>

typedef struct t_image_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_height;
	int		endian;
}	t_image_data;

typedef struct t_data
{
	void	*mlx;
	void	*mlx_window;
	t_image_data *img;
} t_data;

void	error_ex(char *str);
void	put_pixel(t_image_data *img, int x, int y, int color);
void	functions_win(t_data **data);
void	events();
void	draw(char *file);
int		open_file(char *str);
char 	**read_file(char *str);

#endif