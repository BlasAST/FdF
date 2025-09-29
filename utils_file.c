/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:10:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/29 14:32:26 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_ex("Error en la apertura del fichero");
	return (fd);
}

int	points_paint(char *str)
{
	int	i;
	int	size;
	int	in_word;

	i = 0;
	size = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n'
			&& (i == 0 || str[i - 1] == ' '))
			size++;
		i++;
	}
	return (size);
}

char **read_file(char *str)
{
	int	fd;
	char ***lines;
	char *ns;

	fd = open_file(str);
	ns = get_next_line(fd);
	ft_printf("%s", ns);
	ft_printf("%d",points_paint(ns));
	/* while ((ns = get_next_line(fd)) != NULL)
	{
		ft_printf("%d",points_paint(ns));
	} */
	return (NULL);
}