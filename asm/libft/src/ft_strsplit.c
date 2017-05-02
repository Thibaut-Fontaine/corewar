/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:46:01 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 12:01:59 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static size_t	get_tab_len(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 1;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			len++;
		}
		i++;
	}
	return (len + 1);
}

static size_t	get_str_len(char const *s, char c)
{
	size_t		res;
	const char	*sp;

	sp = s;
	res = 0;
	while (*sp != c && *sp != 0)
	{
		sp++;
		res++;
	}
	return (res + 1);
}

static char		**actual_strplit(char **tab, char c, char *fs)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (*fs)
	{
		if (*fs == c)
		{
			while (*fs == c)
				fs++;
			tab[y++][x] = 0;
			x = 0;
		}
		if (x == 0)
			tab[y] = ft_strnew(get_str_len(fs, c));
		tab[y][x++] = *fs++;
	}
	tab[++y] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*fs;

	fs = ft_strctrim(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * get_tab_len(fs, c))) || !*fs)
		return (NULL);
	tab = actual_strplit(tab, c, fs);
	free(fs);
	return (tab);
}
