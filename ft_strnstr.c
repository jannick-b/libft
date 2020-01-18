/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:16:56 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/06 15:16:38 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strnstrhelper(char *hs, char *ndl, size_t len)
{
	size_t	hi;
	size_t	ni;

	hi = 0;
	ni = 0;
	while (hs[hi] != '\0' && hi < len)
	{
		if (hs[hi] == ndl[ni])
		{
			ni++;
			if (ndl[ni] == '\0')
				return (&hs[hi - (ni - 1)]);
		}
		else
		{
			hi = hi - ni;
			ni = 0;
		}
		hi++;
	}
	return (NULL);
}

char			*ft_strnstr(const char *haystack, const char *needle, \
							size_t len)
{
	char			*hs;
	char			*ndl;

	hs = (char*)haystack;
	ndl = (char*)needle;
	if (ndl[0] == '\0')
		return (hs);
	return (ft_strnstrhelper(hs, ndl, len));
}
