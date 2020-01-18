/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 17:37:09 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 14:29:47 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_itoa_posneg(int *n)
{
	int posneg;

	posneg = 0;
	if (*n == -2147483648)
	{
		posneg = 2;
		*n = 2147483647;
	}
	if (*n < 0)
	{
		posneg = 1;
		*n = *n * -1;
	}
	return (posneg);
}

static	int	ft_itoa_size(int n, int posneg)
{
	int size;

	size = 1 + posneg;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	if (posneg == 2)
		size--;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		posneg;

	posneg = ft_itoa_posneg(&n);
	i = ft_itoa_size(n, posneg);
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (str);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (posneg > 0)
	{
		str[0] = '-';
		if (posneg == 2)
			str[ft_strlen(str) - 1] = '8';
		return (str);
	}
	return (str);
}
