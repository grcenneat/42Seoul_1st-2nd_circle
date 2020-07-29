/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysimok <hysimok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:22:15 by hjung             #+#    #+#             */
/*   Updated: 2020/07/29 19:13:15 by hysimok          ###   ########.fr       */
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
    int				type;
}					t_flags;

//입력값 처리
int 	ft_printf(const char *input, ...);
int		ft_treat_fmt(const char *fmt, va_list ap);
int		ft_flag_parse(const char *fmt, int i, t_flags *flags, va_list ap);

//flag 파싱
t_flags	ft_flag_minus(t_flags flags);
int		ft_flag_dot(const char *save, int start,
			t_flags *flags, va_list args);
t_flags	ft_flag_width(va_list args, t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);

//flag 처리
int		ft_treat_width(int width, int minus, int has_zero);

//specifier 처리
int		ft_branch_type(int c, t_flags flags, va_list ap);
int		ft_treat_char(char c, t_flags flags);

//utility
int		ft_putchar(int c);

int		ft_is_in_type_list(int c);
int		ft_is_in_flags_list(int c);

#endif