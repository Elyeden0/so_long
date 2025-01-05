/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:43:52 by abonnard          #+#    #+#             */
/*   Updated: 2024/10/27 18:59:13 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_chunk(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_next_buffer(buffer);
	if (!buffer)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
