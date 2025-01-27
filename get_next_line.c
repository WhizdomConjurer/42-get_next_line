/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whi <whi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:45:48 by whi               #+#    #+#             */
/*   Updated: 2025/01/27 16:01:53 by whi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nl_position;
	size_t		readed_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!(nl_position = ft_strchr(line, '\n')) && 
		(readed_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (readed_bytes < 0 || (!*line && readed_bytes == 0))
		return(free(line), NULL);
	if (nl_position)
	{
		ft_strcpy(buffer, nl_position + 1);
		line[nl_position - line + 1] = '\0';
	}
	else
	{
		buffer[0] = '\0';
	}
	return line;
}

int main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	char *l;
	while ((l = get_next_line(fd)))
	{
	printf("%s\n", l);
	free(l);
	}
	close(fd);
	return (0);
}