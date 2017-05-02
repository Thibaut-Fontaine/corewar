/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:29:58 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:15 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	n = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + n));
	while (n > 0)
	{
		n--;
		if (*(s + n) == (char)c)
			return ((char *)(s + n));
	}
	return (NULL);
}
