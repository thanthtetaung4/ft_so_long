/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:00:15 by msanjuan          #+#    #+#             */
/*   Updated: 2024/10/20 02:05:04 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*f_strchr_gnl(char *s, int c);
char	*f_strjoin_gnl(char *s1, char *s2);
char	*f_strdup_gnl(char *s1);
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);

#endif
