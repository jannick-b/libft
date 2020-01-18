/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 19:16:26 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 14:16:15 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	if (dst == NULL && src == NULL)
		return (NULL);
	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	if (src2 < dst2)
	{
		while (n > 0)
		{
			dst2[n - 1] = src2[n - 1];
			i++;
			n--;
		}
	}
	else
		ft_memcpy(dst2, src2, n);
	return (dst2);
}
