/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:23:44 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/20 21:16:54 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** this version works for UTF-8 formatted strings (wchar_t*)
*/

void			ft_putwstr_fd(wchar_t const *s, int fd)
{
	size_t		i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != 0)
		ft_putwchar_fd(s[i++], fd);
}
