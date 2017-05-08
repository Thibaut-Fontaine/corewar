/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:54:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/25 01:53:23 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

size_t			ft_evaluatepint(intmax_t data)
{
	size_t		r;

	if (data == 0)
		return (1);
	r = 0;
	if (data < 0)
	{
		data = -data;
		++r;
	}
	while (data)
	{
		data /= 10;
		++r;
	}
	return (r);
}

size_t			ft_evaluatepbase(uintmax_t data, int base)
{
	size_t		r;

	if (data == 0)
		return (1);
	r = 0;
	while (data)
	{
		data /= base;
		++r;
	}
	return (r);
}

size_t			ft_evaluintret(const char *t, uintmax_t data)
{
	return (ft_evaluatepbase((unsigned long int)data, *t == 'X'
				|| *t == 'x' ? 16 : ((*t == 'u') * 10 + (*t == 'o') * 8)));
}

void			ft_flagf(const char *s, t_size *t, t_datas dd, int flag)
{
	const char	*type;

	type = ft_gettype(s);
	ft_fflag(s, flag, dd, 2);
	t->print += ft_field(s + t->conv, (ft_evaluate_len(type, dd.data,
					dd.precision) + t->print + ((dd.precision != -1)
						* ft_issigned(*type) * !ft_whichsign(type, dd.data))),
			flag, dd.fd);
	ft_flag(s, dd.data, dd.fd, flag);
	ft_fflag(s, flag, dd, 0);
	t->print += ft_printdata(type, dd.data, dd.fd, dd.precision);
	if ((dd.precision != -1) && ft_issigned(*type)
			&& !ft_whichsign(type, dd.data))
		t->print += 1;
}
