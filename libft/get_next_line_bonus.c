/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:10:49 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/24 14:42:58 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft.h"

char	*ft_join(char *data, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(data, buffer);
	if (!temp)
	{
		free(data);
		return (NULL);
	}
	free(data);
	return (temp);
}

char	*get_next_buffer(char *buffer)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - len + 1, sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	len++;
	i = 0;
	while (buffer[len])
		line[i++] = buffer[len++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_chunk(int fd, char *data)
{
	char	*buffer;
	int		data_read;

	if (!data)
		data = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	data_read = 1;
	while (data_read > 0)
	{
		data_read = read(fd, buffer, BUFFER_SIZE);
		if (data_read == -1)
		{
			free(buffer);
			free(data);
			return (NULL);
		}
		buffer[data_read] = 0;
		data = ft_join(data, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
	{
		if (buffers[fd])
		{
			free(buffers[fd]);
			buffers[fd] = NULL;
		}
		return (NULL);
	}
	buffers[fd] = read_chunk(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = ft_line(buffers[fd]);
	if (!line)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	buffers[fd] = get_next_buffer(buffers[fd]);
	return (line);
}
