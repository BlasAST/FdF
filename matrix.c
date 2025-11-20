/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:11:09 by blas              #+#    #+#             */
/*   Updated: 2025/11/20 14:57:56 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_point_color(char *token)
{
	char	*comma_ptr;
	char	*base;

	base = "0123456789ABCDEF";
	comma_ptr = ft_strchr(token, ',');
	if (comma_ptr)
	{
		return (ft_atoi_base(comma_ptr + 3, (char *) base));
	}
	return (0xFFFFFF);
}

void	fill_matrix_row(t_data *dt, char *line, int y)
{
	char	**strs;
	int		x;

	dt->map[y] = (t_point *)malloc(sizeof(t_point) * dt->map_size_w);
	if (!dt->map[y])
		free_partial_map_and_exit(dt, y - 1);
	strs = ft_split(line, ' ');
	if (!strs)
		free_partial_map_and_exit(dt, y - 1);
	x = 0;
	while (x < dt->map_size_w)
	{
		if (!strs[x])
		{
			free_split(strs);
			free_partial_map_and_exit(dt, y);
		}
		dt->map[y][x].z = ft_atoi(strs[x]);
		dt->map[y][x].color = get_point_color(strs[x]);
		dt->map[y][x].x = x;
		dt->map[y][x].y = y;
		x++;
	}
	free_split(strs);
}

void	do_matrix(t_data *dt)
{
	t_list	*current;
	int		y;

	dt->map = (t_point **)malloc(sizeof(t_point *) * dt->map_size_h);
	if (!dt->map)
		clean_and_exit(dt, 1, 1, "Error asignación de memoria");
	current = dt->map_lines;
	y = 0;
	while (current != NULL)
	{
		fill_matrix_row(dt, current->content, y);
		current = current->next;
		y++;
	}
	ft_lstclear(&(dt->map_lines), free);
	dt->map_lines = NULL;
}
