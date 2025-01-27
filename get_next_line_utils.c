/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whi <whi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:45:39 by whi               #+#    #+#             */
/*   Updated: 2025/01/27 15:39:45 by whi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;

	ch = (char)c;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == ch)
			return (char *)str;
		str++;
	}
	if (ch == '\0')
		return (char *)str;
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	if (!str || !*str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0'; // Null-Terminator hinzufügen
	return (str);
}

char *ft_strcpy(char *dst, const char *src)
{
	char	*dst_start;

	dst_start = dst;
	while (*src) 
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return dst_start;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	size_t	s1_len;
	char	*dest;

	count = -1;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	dest = (char *)malloc((sizeof (char)) * (s1_len + ft_strlen(s2) +1 ));
	if (!dest)
		return (NULL);
	while (s1[++count])
		dest[count] = s1[count];
	count = -1;
	while (s2[++count])
		dest[s1_len + count] = s2[count];
	dest[s1_len + count] = '\0';
	return (dest);
}
