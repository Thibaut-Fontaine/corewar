/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:45:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 03:35:34 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** renvoie un pointeur sur fonction du genre ssize_t (type i, int fd)
** exemple :
**			ssize_t ft_putuint32_fd(uint32_t i, int fd);
*/

ssize_t				ft_putint_fdr(intmax_t i, int fd)
{
	ssize_t			ret;

	ret = 0;
	if (i + 1 == -9223372036854775807)
		return (ft_putstr_fdr("9223372036854775808", fd) + 1);
	if (i < 0)
	{
		ret += 1;
		i = -i;
	}
	if (i / 10 != 0)
		ret += ft_putint_fdr(i / 10, fd);
	ret += ft_putchar_fdr(i % 10 + '0', fd);
	return (ret);
}

ssize_t				ft_putuint_fdr(uintmax_t i, int fd)
{
	ssize_t			ret;

	ret = 0;
	if (i / 10 != 0)
		ret += ft_putuint_fdr(i / 10, fd);
	ret += ft_putchar_fdr(i % 10 + '0', fd);
	return (ret);
}

ssize_t				ft_putoct_fdr(uintmax_t i, int fd)
{
	ssize_t			ret;

	ret = 0;
	if (i / 8 != 0)
		ret += ft_putoct_fdr(i / 8, fd);
	ret += ft_putchar_fdr(i % 8 + '0', fd);
	return (ret);
}

ssize_t				ft_puthex_fdr(uintmax_t i, int fd)
{
	ssize_t			ret;

	ret = 0;
	if (i / 16 != 0)
		ret += ft_puthex_fdr(i / 16, fd);
	ret += ft_putchar_fdr(i % 16 < 10 ? i % 16 + 48 : i % 16 + 87, fd);
	return (ret);
}

ssize_t				ft_puthexx_fdr(uintmax_t i, int fd)
{
	ssize_t			ret;

	ret = 0;
	if (i / 16 != 0)
		ret += ft_puthexx_fdr(i / 16, fd);
	ret += ft_putchar_fdr(i % 16 < 10 ? i % 16 + 48 : i % 16 + 55, fd);
	return (ret);
}
