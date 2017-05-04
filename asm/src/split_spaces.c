/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:27:13 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/04 15:27:15 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"

int		ft_count_words(char *str)
{
	int i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		i++;
	return (1 + ft_count_words(str + i));
}

char	**split_spaces(char *str)
{
	char	**array;
	int		w;
	int		i;
	int		j;
	int		words;

	array = (char **)malloc((ft_count_words(str) + 1) * sizeof(char*));
	w = 0;
	words = ft_count_words(str);
	while (w < words)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		j = 0;
		while (str[i + j] != ' ' && str[i + j] != '\n'
			&& str[i + j] != '\t' && str[i + j] != '\0')
			j++;
		array[w] = malloc(sizeof(char) * (j + 1));
		*(ft_strncpy(array[w], str + i, j) + j + 1) = '\0';
		str = str + i + j;
		w++;
	}
	array[words] = 0;
	return (array);
}