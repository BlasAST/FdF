/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:31:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 01:53:34 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_split(void *content, void *context)
{
	int		size_temp;
	t_data	*dt;
	char	*line;
	char	**lines;

	dt = (t_data *)context;
	line = (char *)content;
	lines = ft_split(line, ' ');
	size_temp = points_paint_split(lines);
	if (size_temp != dt->map_size_w)
	{
		free_split(lines);
		frees_t_data(dt);
		error_ex("Fichero mal formateado\n", 1);
	}
	free_split(lines);
}

void	check_lines_width(t_data *dt)
{
	ft_lstiter_fdf(dt->map_lines, count_split, dt);
	ft_printf("Fichero valido\n");
}
