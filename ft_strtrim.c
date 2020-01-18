/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 02:14:24 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/11 18:48:41 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_end(char const *s1, char const *set)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s1);
	if (i > 0)
		i--;
	while (i > 0)
	{
		while (s1[i] != set[j])
		{
			j++;
			if (set[j] == '\0')
				return (i);
		}
		i--;
		j = 0;
	}
	return (0);
}

static	int	ft_start(char const *s1, char const *set)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] != set[j])
		{
			j++;
			if (set[j] == '\0')
				return (i);
		}
		i++;
		j = 0;
	}
	return (0);
}

char		*ft_return_trim(char const *s1, int start, int end)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = malloc(sizeof(*dst) * (end - start + 2));
	if (dst == NULL)
		return (NULL);
	while (s1[j] != '\0' && i < end - start + 1)
	{
		dst[i] = s1[start + j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int start;
	int end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*set == '\0')
	{
		start = 0;
		end = ft_strlen(s1);
	}
	else
	{
		start = ft_start(s1, set);
		end = ft_end(s1, set);
	}
	if (start == 0 && end == 0)
		return (ft_strdup("\0"));
	return (ft_return_trim(s1, start, end));
}
