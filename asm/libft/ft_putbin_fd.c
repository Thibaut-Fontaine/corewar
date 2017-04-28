/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:21:44 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/26 08:40:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*
** display a string in binary, with mpl bytes displayed per line
** if mpl = 0, there is no maximum (all bytes are displayed in one line)
*/

void		ft_putbin_fd(const unsigned char *s, size_t len, size_t mpl, int fd)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putstr_fd(ft_bytobi(s[i]), fd);
		++i;
		if (mpl != 0 && i % mpl == 0)
			ft_putchar_fd('\n', fd);
		else
			ft_putchar_fd(' ', fd);
	}
}
