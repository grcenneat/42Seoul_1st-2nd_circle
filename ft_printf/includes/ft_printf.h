/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:22:15 by hjung             #+#    #+#             */
/*   Updated: 2020/08/10 01:50:04 by hjung            ###   ########.fr       */
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
int					ft_printf(const char *input, ...);
int					ft_treat_fmt(const char *fmt, va_list ap);
int					ft_flag_parse(const char *fmt, int i,
					t_flags *flags, va_list ap);

//flag 파싱
t_flags				ft_flag_minus(t_flags flags);
int					ft_flag_dot(const char *save, int start,
					t_flags *flags, va_list args);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);

//flag 처리
int					ft_treat_width(int width, int minus, int has_zero);

//specifier 처리
int					ft_branch_type(int c, t_flags flags, va_list ap);
int					ft_treat_char(char c, t_flags flags);
int					ft_putstrprec(char *str, int precision);
int					ft_treat_string(char *str, t_flags flags);
int					ft_treat_pointer(unsigned long long ull, t_flags flags);
int					ft_treat_int(long i, t_flags flags);
int					ft_treat_uint(unsigned int unsi, t_flags flags);
int					ft_treat_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_treat_percent(t_flags flags);

//utility
int					ft_putchar(int c);
char				*ft_str_tolower(char *str);

int					ft_is_in_type_list(int c);
int					ft_is_in_flags_list(int c);
char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_u_itoa(unsigned int n);
char				*ft_l_itoa(long n);

#endif
