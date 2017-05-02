/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:37:49 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:15 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	if (*s2 == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != 0 && n != 0)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == 0 && j <= n)
				return ((char *)(s1 + i));
		}
		i++;
		n--;
	}
	return (NULL);
}
