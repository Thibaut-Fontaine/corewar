/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:39:22 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/10 11:56:55 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

wchar_t	*ft_wstrdup(const wchar_t *str)
{
	wchar_t	*ret;
	int		i;

	ret = (wchar_t *)malloc(ft_wstrlen(str) * (sizeof(wchar_t) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
