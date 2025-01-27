/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whi <whi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:45:48 by whi               #+#    #+#             */
/*   Updated: 2025/01/27 14:41:57 by whi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int ft)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	char		*nl_position;
	size_t		readed_bytes;

	line = ft_strdup(buffer);
	if (!line)
		return (NULL)
	
}