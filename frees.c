/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:22:12 by blas              #+#    #+#             */
/*   Updated: 2025/11/20 14:23:24 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	frees_t_data(t_data *dt)
{
	if (dt->map_lines)
		ft_lstclear(&(dt->map_lines), free);
	if (dt->map)
		free_map(dt->map, dt->map_size_h);
	free(dt);
}

void	free_partial_map_and_exit(t_data *dt, int y)
{
	while (y >= 0)
	{
		free(dt->map[y]);
		y--;
	}
	free(dt->map);
	dt->map = NULL;
	clean_and_exit(dt, 1, 1, "Error: Memoria insuficiente para el mapa\n");
}

void	clear_image(t_data *dt)
{
	ft_bzero(dt->i_d.addr, dt->map_size_w_view * dt->map_size_h_view * \
	(dt->i_d.bit_per_pixel / 8));
}
