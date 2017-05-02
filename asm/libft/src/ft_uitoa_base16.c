/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:20 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

char	*ft_uitoa_base16(uintmax_t n, int base)
{
	int		i;
	char	*s;

	if (n == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	s = ft_strnew(ft_unbrlen(n));
	i = 0;
	while (n > 0)
	{
		s[i] = (n % base < 10 ? (n % base) + '0' : (n % base) + 'a' - 10);
		n = n / base;
		i++;
	}
	s[i] = '\0';
	return (ft_strrev(s));
}
