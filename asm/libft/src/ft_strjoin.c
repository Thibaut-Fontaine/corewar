/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:35:38 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 10:05:01 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fs;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fs = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (fs == NULL)
		return (NULL);
	p = fs;
	while (*s1 != 0)
	{
		*p = *s1;
		p++;
		s1++;
	}
	while (*s2 != 0)
	{
		*p = *s2;
		p++;
		s2++;
	}
	*p = 0;
	return (fs);
}
