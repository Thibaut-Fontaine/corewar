/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:31:17 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 11:41:21 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	char	*res;

	fs = ft_strnew(ft_strlen(s));
	if (fs == NULL)
		return (NULL);
	res = fs;
	while (*s != 0)
	{
		*fs = (*f)(*s);
		fs++;
		s++;
	}
	*fs = 0;
	return (res);
}
