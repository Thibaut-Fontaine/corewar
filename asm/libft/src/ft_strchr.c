/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:00:43 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/10 11:20:22 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res != 0)
	{
		if (*res == (char)c)
			return (res);
		res++;
	}
	if (c == 0)
		return (res);
	return (NULL);
}
