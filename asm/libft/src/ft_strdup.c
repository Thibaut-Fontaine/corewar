/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:39:22 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/10 11:56:55 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incl/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p1;
	char	*p2;
	char	*ret;

	p1 = (char *)s1;
	p2 = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p2 == NULL)
		return (NULL);
	ret = p2;
	while (*p1 != 0)
	{
		*p2 = *p1;
		p1++;
		p2++;
	}
	*p2 = 0;
	return (ret);
}
