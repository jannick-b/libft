/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:52:05 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/15 21:10:42 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is20digits(const char *str)
{
	int i;

	i = 1;
	if (ft_strlen(str) < 20)
		return (0);
	while (str[i] != '\0' && ft_isdigit(str[i]) != 0)
	{
		i++;
	}
	if (i >= 20)
		return (1);
	return (0);
}

static	int	ft_islongmin(const char *str)
{
	if (ft_strlen(str) < 20)
		return (0);
	if (str[1] < '9' || str[2] < '2' || str[3] < '2' || str[4] < '3')
		return (0);
	if (str[5] < '3' || str[6] < '7' || str[7] < '2' || str[8] < '0')
		return (0);
	if (str[9] < '3' || str[10] < '6' || str[11] < '8' || str[12] < '5')
		return (0);
	if (str[13] < '4' || str[14] < '7' || str[15] < '7' || str[16] < '5')
		return (0);
	if (str[17] < '8' || str[18] < '0' || str[19] < '8')
		return (0);
	return (1);
}

static	int	ft_checkplmi(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (ft_is20digits(str) > 0 && ft_islongmin(str) > 0)
			return (-1);
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	result;
	long	newresult;

	if (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'\
		|| *str == '\r' || *str == '\n')
		return (ft_atoi(str + 1));
	i = ft_checkplmi(str);
	if (i == -1)
		return (0);
	result = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		newresult = result * 10 + (str[i] - 48);
		if (newresult < result)
			return (-1);
		result = newresult;
		i++;
	}
	if (*str == '-')
		return (result * -1);
	return (result);
}
