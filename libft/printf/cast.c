/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 01:25:56 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/20 18:38:59 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

ssize_t			ft_typeint(const char *t, uintmax_t data, int fd)
{
	if (*t == 'D')
		return (ft_type(t)((long int)data, fd));
	if (*t == 'd' || *t == 'i')
	{
		if (*(t - 1) == 'h')
		{
			if (*(t - 2) == 'h')
				return (ft_type(t)((char)data, fd));
			else
				return (ft_type(t)((short int)data, fd));
		}
		if (*(t - 1) == 'l' || *(t - 1) == 'j' || *(t - 1) == 'z')
			return (ft_type(t)((long int)data, fd));
		return (ft_type(t)((int)data, fd));
	}
	return (0);
}

ssize_t			ft_typeuint(const char *t, uintmax_t data, int fd)
{
	if (*t == 'U' || *t == 'O')
		return (ft_type(t)((unsigned long int)data, fd));
	if (*t == 'u' || *t == 'o' || *t == 'x' || *t == 'X')
	{
		if (*(t - 1) == 'h')
		{
			if (*(t - 2) == 'h')
				return (ft_type(t)((unsigned char)data, fd));
			else
				return (ft_type(t)((unsigned short int)data, fd));
		}
		if (*(t - 1) == 'l' || *(t - 1) == 'j' || *(t - 1) == 'z')
			return (ft_type(t)((unsigned long int)data, fd));
		return (ft_type(t)((unsigned int)data, fd));
	}
	return (0);
}
