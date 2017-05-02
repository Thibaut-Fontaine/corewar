/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:36:57 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 11:42:34 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fs;
	char	*res;

	fs = ft_strnew(ft_strlen(s));
	if (fs == NULL)
		return (NULL);
	res = fs;
	i = 0;
	while (*s != 0)
	{
		*fs = (*f)(i, *s);
		fs++;
		s++;
		i++;
	}
	*fs = 0;
	return (res);
}
