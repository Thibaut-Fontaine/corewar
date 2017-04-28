/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:42:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/26 14:29:27 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_putadr_fd(void *p, int fd)
{
	uintmax_t	i;
	char		*s;

	i = ft_endian((uintmax_t)p, FALSE);
	ft_putstr_fd("0x", fd);
	if (p == NULL)
		return (ft_putchar_fd('0', fd));
	while ((unsigned char)i == 0)
		i >>= 8;
	if (*(s = (char*)ft_bytohex(i, 1)) == '0')
		ft_putchar_fd(s[1], fd);
	else
		ft_putstr_fd(s, fd);
	while (i >>= 8)
		ft_putstr_fd(ft_bytohex(i, 1), fd);
}
