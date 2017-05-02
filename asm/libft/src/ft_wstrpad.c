/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrpad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:10 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static wchar_t	*fill_space(wchar_t *str, size_t width)
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

wchar_t			*ft_wstrpad(wchar_t *str, size_t width, char side)
{
	wchar_t	*tmp;

	tmp = ft_wstrdup(str);
	free(str);
	str = fill_space(ft_wstrnew(width), width);
	if (side == 'l')
		ft_wstrncpy(str, tmp, ft_wstrlen(tmp));
	else
		ft_wstrncpy(str + (width - ft_wstrlen(tmp)), tmp, ft_wstrlen(tmp));
	free(tmp);
	return (str);
}
