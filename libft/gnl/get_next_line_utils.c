/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:43:28 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/04 12:19:30 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_find(char *str, char c)
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

char	*ft_strdup_gnl(char *str)
{
	char	*new_str;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen_gnl(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_strcpy(char *dest, char *str, char c)
{
	int	i;

	i = 0;
	if (!dest || !str)
		return ;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == c && c == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
}

char	*ft_realloc(char *last_buffer, char *buffer)
{
	char	*temp;
	int		len1;
	int		len2;

	if (!buffer)
		return (NULL);
	len1 = ft_strlen_gnl(last_buffer);
	len2 = ft_strlen_gnl(buffer);
	temp = malloc (sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, last_buffer, '\0');
	ft_strcpy(temp + len1, buffer, '\0');
	free(last_buffer);
	return (temp);
}
