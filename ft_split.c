/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbreiten <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 17:34:19 by jbreiten      #+#    #+#                 */
/*   Updated: 2019/12/17 14:19:44 by jbreiten      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_wordlen(char const *s, char c, int wnbr)
{
	int	count;
	int	letters;

	letters = 0;
	count = 0;
	while (*s == c && *s != '\0')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
		{
			count++;
			if (count < wnbr)
				letters = 0;
		}
		if (count >= wnbr)
			return (letters);
		if (*s != c)
			letters++;
		s++;
	}
	return (letters);
}

static	char		**ft_deallocarr(char **sarr, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		free(sarr[i]);
		i++;
	}
	free(sarr);
	return (NULL);
}

static	int			ft_count(char const *s, char c)
{
	int count;

	count = 1;
	while (*s == c && *s != '\0')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			count++;
		s++;
	}
	return (count);
}

static	char		**ft_fillarr(char **sarr, char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s && sarr[j] != NULL)
	{
		while (*s && *s != c)
		{
			sarr[j][i] = *s;
			i++;
			s++;
		}
		while (*s && *s == c)
			s++;
		sarr[j][i] = '\0';
		j++;
		i = 0;
	}
	return (sarr);
}

char				**ft_split(char const *s, char c)
{
	char	**sarr;
	int		i;
	int		count;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = ft_count(s, c);
	sarr = malloc(sizeof(*sarr) * (count + 1));
	if (sarr == NULL)
		return (NULL);
	while (i < count)
	{
		sarr[i] = malloc(sizeof(**sarr) * (ft_wordlen(s, c, i + 1) + 1));
		if (sarr[i] == NULL)
			return (ft_deallocarr(sarr, i + 1));
		i++;
	}
	sarr[count] = NULL;
	sarr = ft_fillarr(sarr, s, c);
	return (sarr);
}
