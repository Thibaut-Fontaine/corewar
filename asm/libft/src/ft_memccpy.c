/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:57 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:14 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dstp;
	const char		*srcp;

	dstp = (char *)dst;
	srcp = (const char *)src;
	while (n > 0)
	{
		*dstp = *srcp;
		if (*(unsigned char *)srcp == (unsigned char)c)
			return (dstp + 1);
		dstp++;
		srcp++;
		n--;
	}
	return (NULL);
}
