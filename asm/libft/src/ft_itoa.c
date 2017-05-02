/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:00:44 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 17:15:47 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	if ((s = ft_strnew(ft_intlen(n))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return ((s = ft_strcpy(s, "-2147483648\0")));
	if (n == 0)
		return ((s = ft_strcpy(s, "0\0")));
	sign = n;
	if (n < 0)
		n = -n;
	i = 0;
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (ft_strrev(s));
}
