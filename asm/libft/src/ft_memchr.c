/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:46:04 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 17:19:08 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	while (n > 0 && *p != (unsigned char)c)
	{
		p++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return (p);
}
