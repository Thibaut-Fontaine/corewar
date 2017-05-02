/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:01 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static char	*inner_itoa(intmax_t n, int base)
{
	uintmax_t	un;
	char		sign;
	int			i;
	char		*s;

	un = n;
	sign = 0;
	if (n < 0)
	{
		un = -n;
		sign = 1;
	}
	s = ft_strnew(ft_nbrlen(un));
	i = 0;
	while (un > 0)
	{
		s[i] = (un % base < 10 ? (un % base) + '0' : (un % base) + 'a' - 10);
		un = un / base;
		i++;
	}
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	return (s);
}

char		*ft_itoa_base16(intmax_t n, int base)
{
	char	*s;

	if (n == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	else
		s = inner_itoa(n, base);
	return (ft_strrev(s));
}
