/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:55:20 by taung             #+#    #+#             */
/*   Updated: 2024/10/14 22:34:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_entity(char c)
{
	char	*entities;
	int		i;

	i = 0;
	entities = "10CEP";
	while (entities[i])
	{
		if (c == entities[i])
			return (1);
	}
	return (0);
}

int	check_valid_path(s_map *map)
{
	return (1);
}

int	check_border(s_map *map)
{
	char*	row;


	return (1);
}
int	check_content(s_map *map)
{
}

int	validate(s_map *map)
{
	int	i;
	int	j;

	i = 0;
	while()
	{

	}
}
