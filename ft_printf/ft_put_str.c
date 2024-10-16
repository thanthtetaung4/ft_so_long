/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:41:51 by taung             #+#    #+#             */
/*   Updated: 2024/10/16 12:41:52 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s);

int	ft_put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_put_char(s[i++]);
	return (i);
}

// int	main(void)
// {
// 	printf("NULL is %d",ft_put_str(NULL));
// }
