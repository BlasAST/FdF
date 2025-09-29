/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/29 12:56:13 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
		exit(0);
	return (0);
}

static int	close_button(t_data *data)
{
	exit(0);
}

void	functions_win(t_data **data)
{
	mlx_hook((*data)->mlx_window, 2, 1L << 0, key_press, (*data));
	mlx_hook((*data)->mlx_window, 17, 0, close_button, (*data));
}

