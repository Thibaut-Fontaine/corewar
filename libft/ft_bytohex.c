/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytobi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:12:53 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/26 08:45:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char			ft_hex_digit(unsigned n, t_bool big_or_little)
{
	if (n < 10)
		return (n + '0');
	else if (big_or_little)
		return ((n - 10) + 'a');
	else
		return ((n - 10) + 'A');
}

const char			*ft_bytohex(unsigned char o, t_bool big_or_little)
{
	static char		hex[3];

	hex[0] = ft_hex_digit(o / 0x10, big_or_little);
	hex[1] = ft_hex_digit(o % 0x10, big_or_little);
	hex[2] = 0;
	return (hex);
}
