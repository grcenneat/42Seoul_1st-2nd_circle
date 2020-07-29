#include "../includes/ft_printf.h"

int		ft_branch_type(int c, t_flags flags, va_list ap)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_treat_char(va_arg(ap, int), flags);
		/*
	else if (c == 's')
		char_count = ft_treat_string(va_arg(ap, char *), flags);
	else if (c == 'p')
		char_count = ft_treat_pointer(va_arg(ap, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_treat_int(va_arg(ap, int), flags);
	else if (c == 'u')
		char_count += ft_treat_uint((unsigned int)va_arg(ap, unsigned int),
		flags);
	else if (c == 'x')
		char_count += ft_treat_hexa(va_arg(ap, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_treat_hexa(va_arg(ap, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_treat_percent(flags);
		*/
	return (char_count);
}