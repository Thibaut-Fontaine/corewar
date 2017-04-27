/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_fdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:42:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/10 11:41:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

ssize_t			ft_putadr_fdr(void *p, int fd)
{
	uintmax_t	i;
	char		*s;
	ssize_t		r;

	i = ft_endian((uintmax_t)p, FALSE);
	r = ft_putstr_fdr("0x", fd);
	if (p == NULL)
		return (r += ft_putchar_fdr('0', fd));
	while ((unsigned char)i == 0)
		i >>= 8;
	if (*(s = (char*)ft_bytohex(i, 1)) == '0')
		r += ft_putchar_fdr(s[1], fd);
	else
		r += ft_putstr_fdr(s, fd);
	while (i >>= 8)
		r += ft_putstr_fdr(ft_bytohex(i, 1), fd);
	return (r);
}
