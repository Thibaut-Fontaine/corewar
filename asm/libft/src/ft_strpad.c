/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:10 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static char	*fill_space(char *str, size_t width)
{
	unsigned int i;

	i = 0;
	while (i < width)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char		*ft_strpad(char *str, size_t width, char side)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	str = fill_space(ft_strnew(width), width);
	if (side == 'l')
		ft_strncpy(str, tmp, ft_strlen(tmp));
	else
		ft_strncpy(str + (width - ft_strlen(tmp)), tmp, ft_strlen(tmp));
	free(tmp);
	return (str);
}
