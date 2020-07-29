/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysimok <hysimok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:58:39 by hjung             #+#    #+#             */
/*   Updated: 2020/07/30 03:26:55 by hysimok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = -1;
	flags->star = 0;
	flags->width = 0;
	flags->type = 0;
}

int		ft_flag_parse(const char *fmt, int i, t_flags *flags, va_list ap)
{
	while (fmt[i])
	{
		if (!ft_isdigit(fmt[i]) && !ft_is_in_type_list(fmt[i])
		&& !ft_is_in_flags_list(fmt[i]))
			break ;
		if (fmt[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (fmt[i] == '.')
			i = ft_flag_dot(fmt, ++i, flags, ap);
		if (fmt[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (fmt[i] == '*')
			*flags = ft_flag_width(ap, *flags);
		if (ft_isdigit(fmt[i]))
			*flags = ft_flag_digit(fmt[i], *flags);
		if (ft_is_in_type_list(fmt[i]))
		{
			flags->type = fmt[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_treat_fmt(const char *fmt, va_list ap)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (fmt[i] != '\0')
	{
		ft_init_flags(&flags);
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i = ft_flag_parse(fmt, ++i, &flags, ap);
			if (ft_is_in_type_list(fmt[i]))
				char_count += ft_branch_type((char)flags.type, flags, ap);
			else if (fmt[i])
				char_count += ft_putchar(fmt[i]);
		}
		else if (fmt[i] != '%')
			char_count += ft_putchar(fmt[i]);
		i++;
	}
	return (char_count);
}

int		ft_printf(const char *input, ...)
{
	const char	*fmt;
	va_list		ap;
	int			output_len;
	int			i;

	i = 0;
	output_len = 0;
	fmt = ft_strdup(input);
	va_start(ap, input);
	output_len += ft_treat_fmt(fmt, ap);
	va_end(ap);
	free((void *)fmt);
	return (output_len);
}
