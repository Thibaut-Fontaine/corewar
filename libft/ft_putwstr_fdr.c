/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:23:44 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/10 11:46:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** this version works for UTF-8 formatted strings (wchar_t*)
*/

ssize_t			ft_putwstr_fdr(wchar_t const *s, int fd)
{
	size_t		i;
	ssize_t		r;

	if (s == NULL)
		return (-1);
	i = 0;
	r = 0;
	while (s[i] != 0)
		r += ft_putwchar_fdr(s[i++], fd);
	return (r);
}
