/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:27:48 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 14:23:59 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_sizes_fdf(t_data *dt, char *file)
{
	char	**strs;
	int		points;

	dt->file = file;
	dt->map_lines = read_file(dt->file);
	if (dt->map_lines == NULL)
	{
		frees_t_data(dt);
		error_ex("Mapa vacio o error de memoria en la lectura\n", 1);
	}
	dt->map_size_h = ft_lstsize(dt->map_lines);
	strs = ft_split(dt->map_lines->content, ' ');
	if (!strs)
	{
		frees_t_data(dt);
		error_ex("Error asignación split", 1);
	}
	points = points_paint_split(strs);
	dt->map_size_w = points;
	free_split(strs);
}
