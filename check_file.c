/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:40:05 by blas              #+#    #+#             */
/*   Updated: 2025/11/20 15:21:33 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_fdf(char *str)
{
	char	*valid_extension;
	int		i;

	if (!str)
		return (1);
	valid_extension = ".fdf";
	i = 0;
	while (str[i] != '\0' || valid_extension[i] != '\0')
	{
		if (str[i] != valid_extension[i])
			return (1);
		i++;
	}
	return (0);
}

char	*check_validate_file_and_save(char *str)
{
	char	*extension;

	extension = ft_strrchr(str, '.');
	if (!extension || check_file_fdf(extension) == 1)
		error_ex("Error file: The extension must be .fdf\n", 1);
	return (str);
}
