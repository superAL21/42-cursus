/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:21:01 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/13 12:52:49 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer_saved;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer_saved = ft_read_fill(fd, buffer_saved);
	line = ft_get_line(buffer_saved);
	buffer_saved = ft_buffer_act(buffer_saved);
	return (buffer_saved);
}

char	*ft_read_fill(int fd, char *buffer_saved)
{
	char	*temp_buffer;
	ssize_t	*bytes_read;
	
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if(!temp_buffer)
		return (NULL);
	while (buffer_saved && buffer_saved != '\n')
	{
		bytes_read = read(fd, buffer_saved, BUFFER_SIZE);
		if(bytes_read == -1)
			return (free(buffer_saved), NULL);
	}
	temp_buffer = ft_substr(buffer_saved, 0, bytes_read);
	return ()
}
