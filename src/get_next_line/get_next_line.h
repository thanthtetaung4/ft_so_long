/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:57:56 by taung             #+#    #+#             */
/*   Updated: 2024/10/14 21:30:39 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

char	*get_next_line(int fd);
// size_t	ft_strlen(const char *str);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*ft_strjoin_gnl(char *line, char *buff);
int		check_newline(const char *str);

#endif
