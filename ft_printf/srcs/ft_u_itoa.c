#include "../includes/ft_printf.h"

static int		ft_num_len(long n)
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

static char		*ft_minus(char *res, long n, int len)
{
	while (n < 0)
	{
		res[--len] = '0' + ((n % 10) * (-1));
		n /= 10;
	}
	res[--len] = '-';
	return (res);
}

char			*ft_u_itoa(unsigned int n)
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