/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:26 by marvin            #+#    #+#             */
/*   Updated: 2025/11/20 01:02:42 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argn, char **args)
{
	t_data	*dt;

	if (argn != 2)
		error_ex("2 params: ./fdf file.fdf\n", 1);
	check_validate_file_and_save(args[1]);
	dt = (t_data *)malloc(sizeof(t_data));
	if (!dt)
		error_ex("Error create data", 1);
	ft_bzero(dt, sizeof(t_data));
	put_sizes_fdf(dt, args[1]);
	do_matrix(dt);
	init_projection(dt);
	create_ini(dt);
	functions_win(dt);
	mlx_loop(dt->mlx_ptr);
	return (0);
}
