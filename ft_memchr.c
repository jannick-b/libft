/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 18:50:56 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 14:15:28 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n && (str[i] != '\0' || uc == '\0'))
	{
		if (str[i] == uc)
			return (str + i);
		i++;
	}
	return (NULL);
}
