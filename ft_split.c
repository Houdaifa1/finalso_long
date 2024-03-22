/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:22:56 by hdrahm            #+#    #+#             */
/*   Updated: 2024/03/21 00:23:04 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_strs(const char *s, char c)
{
	int		i;
	size_t	strl;

	i = 0;
	strl = 0;
	while (s != NULL && *s != '\0')
	{
		if (*s != c && i == 0)
		{
			i = 1;
			strl++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (strl);
}

static size_t	ft_chrs(const char *s, char c)
{
	size_t	chrl;

	chrl = 0;
	while (*s && *s != c)
	{
		chrl++;
		s++;
	}
	return (chrl);
}

static int	ft_free(char **arr, size_t n)
{
	if (!arr[n])
	{
		while (n--)
			free(arr[n]);
		free(arr);
		return (1);
	}
	return (2);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	chrl;
	size_t	strl;
	size_t	n;

	strl = ft_strs(s, c);
	arr = (char **)malloc(sizeof(char *) * (strl + 1));
	if (arr == NULL)
		return (NULL);
	n = 0;
	while (s != NULL && n < strl)
	{
		while (*s == c)
			s++;
		chrl = ft_chrs(s, c);
		arr[n] = (char *)malloc(chrl + 1);
		if (ft_free(arr, n) == 1)
			return (NULL);
		ft_strlcpy(arr[n], s, chrl + 1);
		s = s + chrl;
		n++;
	}
	arr[strl] = NULL;
	return (arr);
}
