/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/20 15:22:21 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

typedef struct t_img
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct t_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct t_data
{
	char			*file;
	void			*mlx_ptr;
	void			*win_ptr;
	struct t_img	i_d;
	int				map_size_w;
	int				map_size_h;
	int				map_size_w_view;
	int				map_size_h_view;
	double			zoom;
	double			angle;
	double			offset_x;
	double			offset_y;
	t_list			*map_lines;
	t_point			**map;
	int				max_z;
}	t_data;

void	create_ini(t_data *df);
void	functions_win(t_data *data);
void	events(void);
int		check_file_fdf(char *str);
char	*check_validate_file_and_save(char *str);
void	check_lines_width(t_data *dt);
int		open_file(char *str);
t_list	*read_file(char *str);
void	put_sizes_fdf(t_data *dt, char *file);
void	ft_lstiter_fdf(t_list *lst, void (*f)(void *content, void *context),
			void *context);
void	do_matrix(t_data *dt);
int		ft_find_fdf(char *str, char c);
int		ft_atoi_base(char *str, char *base);
void	init_projection(t_data *dt);
void	draw_map(t_data *data);
void	put_pixel(t_data *dt, int x, int y, int color);
int		points_paint(char *str);
int		points_paint_split(char **str);
void	put_zoom(t_data *dt);
void	draw_line(t_data *dt, t_point p1, t_point p2);
void	error_ex(char *str, int error);
void	free_split(char **arr);
void	free_map(t_point **map, int height);
void	free_partial_map_and_exit(t_data *dt, int y);
void	frees_t_data(t_data *dt);
void	clear_image(t_data *dt);
void	max_size_z(t_data *dt);
int		clean_and_exit(t_data *data, int code, int exit_print, char *err);
void	finish_fdf(t_data *df);
#endif