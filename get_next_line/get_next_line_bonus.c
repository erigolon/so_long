/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:19:17 by erigolon          #+#    #+#             */
/*   Updated: 2023/02/03 12:44:30 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(char *gl_buffer)
{
	char	*line;
	int		i;
	int		o;

	i = 0;
	while (gl_buffer[i] && gl_buffer[i] != '\n')
		i++;
	if (!gl_buffer[i])
	{
		free(gl_buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(gl_buffer) - i), sizeof(char));
	i++;
	o = 0;
	while (gl_buffer[i])
		line[o++] = gl_buffer[i++];
	free(gl_buffer);
	return (line);
}

char	*the_line(char *gl_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!gl_buffer[i])
		return (NULL);
	while (gl_buffer[i] && gl_buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (gl_buffer[i] && gl_buffer[i] != '\n')
	{
		line[i] = gl_buffer[i];
		i++;
	}
	if (gl_buffer[i] && gl_buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*free_join(char *gl_buffer, char *buffer)
{
	char	*str;

	str = ft_strjoin(gl_buffer, buffer);
	free(gl_buffer);
	return (str);
}

char	*read_file(int fd, char *gl_buffer)
{
	char		*buffer;
	ssize_t		nr_bytes;

	if (!gl_buffer)
		gl_buffer = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nr_bytes = 1;
	while (nr_bytes > 0)
	{
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free(gl_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[nr_bytes] = '\0';
		gl_buffer = free_join(gl_buffer, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (gl_buffer);
}

char	*get_next_line(int fd)
{
	static char	*gl_buffer[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	gl_buffer[fd] = read_file(fd, gl_buffer[fd]);
	if (!gl_buffer[fd])
		return (NULL);
	line = the_line(gl_buffer[fd]);
	gl_buffer[fd] = next_line(gl_buffer[fd]);
	return (line);
}
