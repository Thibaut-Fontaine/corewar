/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:03:29 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:15 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

wchar_t	*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	wchar_t *ret;
	int		i;
	int		j;

	ret = dst;
	i = 0;
	j = 0;
	while (n > 0)
	{
		if (src[i] == 0)
			dst[j++] = 0;
		else
			dst[j++] = src[i++];
		n--;
	}
	return (ret);
}
