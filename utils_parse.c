/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:06:03 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 15:24:34 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstiter_fdf(t_list *lst, void (*f)(void *content, void *context),
void *context)
{
	while (lst != NULL)
	{
		f(lst->content, context);
		lst = lst->next;
	}
}

int	ft_find_fdf(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
