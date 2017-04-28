/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:53:32 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/26 08:43:23 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*
** write len bytes from the string in hexadecimal, mpl max per line.
** if mpl is 0, no maximum per line.
*/

void		ft_puthex_fd(const unsigned char *s,
		size_t len, size_t mpl, int fd)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putstr_fd(ft_bytohex(s[i], 0), fd);
		++i;
		if (mpl != 0 && i % mpl == 0)
			ft_putchar_fd('\n', fd);
		else
			ft_putchar_fd(' ', fd);
	}
}
