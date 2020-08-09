/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:02:41 by hjung             #+#    #+#             */
/*   Updated: 2020/08/09 18:22:22 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

int			ft_flag_dot(const char *fmt, int i,
			t_flags *flags, va_list ap)
{
	if (fmt[i] == '*')
	{
		flags->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(fmt[i]))
			flags->dot = (flags->dot * 10) + (fmt[i++] - '0');
	}
	return (i);
}

t_flags		ft_flag_width(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
