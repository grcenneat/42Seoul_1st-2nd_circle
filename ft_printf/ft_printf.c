/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysimok <hysimok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 01:13:55 by hysimok           #+#    #+#             */
/*   Updated: 2020/07/16 02:22:32 by hysimok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int ft_printf(const char *input, ...)
{
    const char  *buff;
    va_list     ap;
    int         output_len = 0;
    int         i, d;
    char        c;

    i = 0;
    buff = ft_strdup(input);
    va_start(ap, input);
    while (buff[i])
    {
        switch(buff[i++])
        {
            case 'c':
                c = va_arg(ap, int);
                printf("character %c\n", c);
                break;
            case 'd':
                d = va_arg(ap, int);
                printf("integer %d\n", d);
                break;
        }
    }
    va_end(ap);
    free((void *)buff);
    return(output_len);
}