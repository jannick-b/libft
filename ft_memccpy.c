/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 22:04:05 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 14:15:11 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	uc;

	uc = (unsigned char)c;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	while (i < n && src2[i] != uc)
	{
		dst2[i] = src2[i];
		i++;
	}
	if (src2[i] == uc)
	{
		dst2[i] = src2[i];
		return (dst2 + i + 1);
	}
	return (NULL);
}
