/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logbasen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:04 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/09 20:23:29 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

size_t		ft_logbasen(intmax_t n, char base)
{
	size_t		len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
