/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fdr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:15:38 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/10 11:50:16 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

ssize_t		ft_putwchar_fdr(wchar_t c, int fd)
{
	if (c <= 0x7F)
		return (ft_putchar_fdr(c, fd));
	else if (c <= 0x7FF)
		return (ft_putchar_fdr((c >> 6) + 0xC0, fd)
				+ ft_putchar_fdr((c & 0x3F) + 0x80, fd));
	else if (c <= 0xFFFF)
		return (ft_putchar_fdr((c >> 12) + 0xE0, fd)
				+ ft_putchar_fdr(((c >> 6) & 0x3F) + 0x80, fd)
				+ ft_putchar_fdr((c & 0x3F) + 0x80, fd));
	else if (c <= 0x10FFFF)
	{
		return (ft_putchar_fdr((c >> 18) + 0xF0, fd)
				+ ft_putchar_fdr(((c >> 12) & 0x3F) + 0x80, fd)
				+ ft_putchar_fdr(((c >> 6) & 0x3F) + 0x80, fd)
				+ ft_putchar_fdr((c & 0x3F) + 0x80, fd));
	}
	else
		return (-1);
}
