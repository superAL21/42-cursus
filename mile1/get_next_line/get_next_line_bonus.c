/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:21:01 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/20 12:00:24 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer_saved[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buffer_saved[fd] = ft_read_fill(fd, buffer_saved[fd]);
	if (!buffer_saved[fd])
		buffer_saved[fd] = ft_strdup("");
	line = ft_get_line(buffer_saved[fd]);
	buffer_saved[fd] = ft_buffer_act(buffer_saved[fd]);
	return (line);
}

char	*ft_read_fill(int fd, char *buffer_saved)
{
	char	*temp_buffer;
	ssize_t	bytes_read;
	char	*temp_ptr;

	if (!buffer_saved)
		buffer_saved = ft_strdup("");
	if (!buffer_saved)
		return (NULL);
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer_saved, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer_saved), free(temp_buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		temp_ptr = buffer_saved;
		buffer_saved = ft_strjoin_free(temp_ptr, temp_buffer);
	}
	free(temp_buffer);
	return (buffer_saved);
}

char	*ft_get_line(char *buffer_saved)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer_saved[i])
		return (NULL);
	while (buffer_saved[i] != '\0' && buffer_saved[i] != '\n')
		i++;
	if (buffer_saved[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		line[j] = buffer_saved[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_buffer_act(char *buffer_saved)
{
	int		i;
	char	*temp;

	if (!buffer_saved)
		return (NULL);
	i = 0;
	while (buffer_saved[i] != '\0' && buffer_saved[i] != '\n')
		i++;
	if (!buffer_saved[i])
	{
		free(buffer_saved);
		return (NULL);
	}
	temp = ft_substr(buffer_saved, i + 1, (ft_strlen(buffer_saved) - i - 1));
	free(buffer_saved);
	if (temp && *temp == '\0')
		return (free(temp), NULL);
	return (temp);
}
