/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:39:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/10 13:42:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t			ft_putnbr_fdr(int nb, int fd)
{
	ssize_t		r;

	r = 0;
	if (nb < 0)
	{
		r += ft_putchar_fdr('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		r += ft_putnbr_fdr(nb / 10, fd) + ft_putnbr_fdr(nb % 10, fd);
	else
		r += ft_putchar_fdr(nb + '0', fd);
	return (r);
}
