/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:43:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/04 12:19:30 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_last_buff(char **last, char *buff, int bytes)
{
	char	*temp;

	free(buff);
	if (*last && **last != '\0' && bytes != -1)
	{
		temp = ft_strdup_gnl(*last);
		free (*last);
		*last = NULL;
		return (temp);
	}
	else if (*last || (*last && bytes == -1))
	{
		free(*last);
		*last = NULL;
	}
	return (NULL);
}

char	*modify_last_buff(char **last_buffer)
{
	int		pos;
	char	*temp;
	char	*new;

	pos = ft_find(*last_buffer, '\n');
	if (pos == -1)
		return (ft_clean_last_buff(last_buffer, NULL, -1));
	temp = malloc(sizeof(char) * pos + 2);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, *last_buffer, '\n');
	new = ft_strdup_gnl(*last_buffer + pos + 1);
	if (!new)
	{
		free (temp);
		return (NULL);
	}
	free(*last_buffer);
	*last_buffer = new;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*last_buffer;
	char		*buffer;
	int			bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_find(last_buffer, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_clean_last_buff(&last_buffer, buffer, bytes));
		buffer[bytes] = '\0';
		last_buffer = ft_realloc(last_buffer, buffer);
	}
	free(buffer);
	return (modify_last_buff(&last_buffer));
}
