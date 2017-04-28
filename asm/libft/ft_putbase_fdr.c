/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 00:34:17 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 03:32:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

ssize_t			ft_putbase_fdr(uintmax_t i, unsigned int base, int fd)
{
	return (i != 0 ? ft_putbase_fdr(i / base, base, fd)
			+ ft_putchar_fdr((i % base < 10) * (i % base + 48)
				+ !(i % base < 10) * i % base + 55, fd) : 0);
}
