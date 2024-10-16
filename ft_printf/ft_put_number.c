/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:41:38 by taung             #+#    #+#             */
/*   Updated: 2024/10/16 12:41:40 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_number(int n);

int	ft_put_number(int n)
{
	int		length;
	char	*str;

	length = 0;
	str = ft_itoa(n);
	length = ft_put_str(str);
	free(str);
	return (length);
}
