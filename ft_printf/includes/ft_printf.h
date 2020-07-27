/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysimok <hysimok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:01:03 by hysimok           #+#    #+#             */
/*   Updated: 2020/07/18 12:31:23 by hysimok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/libft.h"

# define ERROR -1

typedef	struct		s_flags
{
	int				already_print;
	int				minus;
	int				zero;
	int				dot;
	int				star;
    int				width;
    char			type;
}					t_flags;

int 	ft_printf(const char *input, ...);
int		ft_treat_fmt(const char *fmt, va_list ap);
int		ft_flag_parse(const char *fmt, int i, t_flags *flags, va_list ap);
t_flags	ft_flag_minus(t_flags flags);

int		ft_putchar(char c);

#endif