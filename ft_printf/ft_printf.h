#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_put_char(char c);
int	ft_put_str(char *s);
int	ft_put_number(int n);
int	ft_put_unumber(unsigned int n);
int	ft_put_hexa(unsigned long long n, const char formet);
int	ft_put_ptr(void *ptr);

#endif
