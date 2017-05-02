/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:27:41 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 17:19:34 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pd;
	char		*ps;

	pd = dst;
	ps = (char *)src;
	if (pd <= ps)
		while (len--)
			*pd++ = *ps++;
	else
	{
		pd += len - 1;
		ps += len - 1;
		while (len--)
			*pd-- = *ps--;
	}
	return (dst);
}
