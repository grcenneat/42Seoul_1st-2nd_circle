/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:32:31 by hjung             #+#    #+#             */
/*   Updated: 2020/08/10 05:14:06 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_percent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
	{
		char_count += ft_putstrprec("%", 1);
		char_count += ft_treat_width(flags.width, 1, 0);
	}
	if (flags.minus == 0)
	{
		char_count += ft_treat_width(flags.width, 1, flags.zero);
		char_count += ft_putstrprec("%", 1);
	}
	return (char_count);
}
