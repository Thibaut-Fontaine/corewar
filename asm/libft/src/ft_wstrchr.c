/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:00:43 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/10 11:20:22 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

wchar_t	*ft_wstrchr(const wchar_t *s, wchar_t c)
{
	wchar_t	*res;
	int		i;

	res = (wchar_t *)s;
	i = 0;
	while (res[i] != 0)
	{
		if (res[i] == c)
			return (&(res[i]));
		i++;
	}
	if (c == 0)
		return (&(res[i]));
	return (NULL);
}
