/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:41:45 by taung             #+#    #+#             */
/*   Updated: 2024/10/16 12:41:46 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(void *ptr);

int	ft_put_ptr(void *ptr)
{
	unsigned long long	p;
	unsigned int		print_char;

	if (!ptr)
		return (write(1, "(nil)", 5));
	p = (unsigned long long)ptr;
	print_char = 0;
	if (p == 0)
		print_char += ft_put_str("(nil)");
	print_char += ft_put_str("0x");
	print_char += ft_put_hexa(p, 'x');
	return (print_char);
}

// int	main(void)
// {
// 	int		i;
// 	int *	ptr;

// 	i = 10;

// 	ft_put_ptr(NULL);
// 	printf("\nprintf: %p\n",NULL);
// 	printf("%s","hi");
// }
