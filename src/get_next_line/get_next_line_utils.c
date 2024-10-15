/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:57:56 by taung             #+#    #+#             */
/*   Updated: 2024/10/14 21:28:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

int	check_newline(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dl;

	i = 0;
	j = ft_strlen(dst);
	dl = j;
	if (size <= dl)
		return (size + ft_strlen(src));
	while (src[i] && i + dl + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (j < size)
		dst[j] = '\0';
	return (dl + ft_strlen(src));
}

char	*ft_strjoin_gnl(char *line, char *buff)
{
	size_t	j;
	size_t	len;
	char	*str;

	j = 0;
	if (!line)
	{
		line = (char *)malloc(1);
		if (!line || !buff)
			return (NULL);
		line[0] = '\0';
	}
	else
		j = ft_strlen(line);
	len = j + ft_strlen(buff);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy_gnl(str, line, j + 1);
	ft_strlcat_gnl(str, buff, len + 1);
	free(line);
	return (str);
}
