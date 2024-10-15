/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:57:56 by taung             #+#    #+#             */
/*   Updated: 2024/10/14 21:29:47 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*handle_eof(char *line, char **buffer, int br)
{
	free(*buffer);
	if (br == 0)
	{
		if (line && line[0])
			return (line);
		else
			return (NULL);
	}
	return (NULL);
}

char	*read_line(int fd, char *store)
{
	char	*buffer;
	int		br;
	char	*line;
	int		foundnl;

	foundnl = 0;
	line = store;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!(foundnl))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br > 0)
		{
			buffer[br] = '\0';
			foundnl = check_newline(buffer);
			line = ft_strjoin_gnl(line, buffer);
		}
		else
			return (handle_eof(line, &buffer, br));
	}
	free(buffer);
	return (line);
}

char	*get_store(char *line)
{
	size_t	i;
	size_t	j;
	char	*store;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	store = malloc(ft_strlen(line) - i + 1);
	if (!store)
		return (NULL);
	j = 0;
	while (line[i + j])
	{
		store[j] = line[i + j];
		j++;
	}
	store[j] = '\0';
	return (store);
}

char	*get_res_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = line[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*store = NULL;
	char		*line;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, store);
	if (!line)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	res = get_res_line(line);
	store = get_store(line);
	free(line);
	return (res);
}
// #include<fcntl.h>

// int	main(void)
// {
// 	int			fd;
// 	const char	*path;

// 	path = "1char.txt";
// 	// path = "test.txt";
// 	// path = "test-long.txt";
// 	printf("BUFFER_SIZE -> %i\n",BUFFER_SIZE);
// 	fd = open(path, O_RDONLY);
// 	printf("res1 : %s", get_next_line(fd));
// 	// printf("\n-----------\n");
// 	printf("res2 : %s", get_next_line(fd));
// 	// printf("\n-----------\n");
// 	printf("res3 : %s", get_next_line(fd));
// 	// printf("\n-----------\n");
// 	printf("res4 : %s", get_next_line(fd));
// 	// printf("\n-----------\n");
// 	printf("res5 : %s", get_next_line(fd));
// }
