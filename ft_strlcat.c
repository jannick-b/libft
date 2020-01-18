/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 22:21:46 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 13:52:00 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	di;
	size_t	si;

	si = 0;
	di = 0;
	slen = ft_strlen(src);
	dlen = 0;
	while (dst[di] != '\0' && dstsize > 0)
	{
		di++;
		dlen++;
		dstsize--;
	}
	while (src[si] != '\0' && dstsize > 1)
	{
		dst[di] = src[si];
		di++;
		si++;
		dstsize--;
	}
	if ((src[si] == '\0' && src[0] != '\0') || dstsize == 1)
		dst[di] = '\0';
	return (dlen + slen);
}
