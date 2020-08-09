/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 01:45:26 by hjung             #+#    #+#             */
/*   Updated: 2020/08/10 01:47:24 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_num_len(long n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_minus(char *res, long n, int len)
{
	while (n < 0)
	{
		res[--len] = '0' + ((n % 10) * (-1));
		n /= 10;
	}
	res[--len] = '-';
	return (res);
}

char		*ft_l_itoa(long n)
{
	char	*res;
	int		len;

	len = ft_num_len(n) + 2;
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	res[--len] = '\0';
	if (n < 0)
		res = ft_minus(res, n, len);
	else if (n == 0)
		res[--len] = '0';
	else
	{
		res[--len] = '\0';
		while (n > 0)
		{
			res[--len] = '0' + (n % 10);
			n /= 10;
		}
	}
	return (res);
}
