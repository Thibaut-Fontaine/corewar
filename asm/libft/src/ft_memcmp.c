/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:49:14 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 17:15:57 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0 && *p1 == *p2)
	{
		p1++;
		p2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((int)(*p1 - *p2));
}
