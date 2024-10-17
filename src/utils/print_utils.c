/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:53:11 by taung             #+#    #+#             */
/*   Updated: 2024/10/18 02:01:13 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_map(s_map *map_data)
{
	int	i;

	i = 0;
	while(i < map_data->rows)
	{
		ft_putstr_fd(map_data->map[i],1);
		ft_putchar_fd('\n',1);
		i++;
	}
}
