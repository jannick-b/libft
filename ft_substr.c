/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:31:38 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 14:18:56 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned long	si;
	unsigned long	di;

	if (s == NULL)
		return (NULL);
	di = 0;
	si = 0;
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (dst);
	while (s[start] != '\0' && di < len)
	{
		dst[di] = s[start];
		di++;
		start++;
	}
	dst[di] = '\0';
	return (dst);
}
