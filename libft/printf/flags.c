/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:38:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/25 22:00:09 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static size_t		ft_flagtag(const char *s, t_datas dd, t_bool *tag,
		int flag)
{
	size_t			r;
	const char		*t;
	int				precision;

	t = ft_gettype(s);
	if (*t != 'o')
		return (0);
	precision = ft_getprecision(s, *t);
	if (*tag != TRUE)
	{
		*tag = TRUE;
		if (dd.data == 0 && precision == -1)
			return (0);
		if (dd.data == 0 && precision == 0)
			return (ft_putchar_fdr('0', dd.fd));
		r = ft_flagtag_calculate(s);
		if ((precision != -1 && (ft_evaluate_uint(t, dd.data) >=
						(size_t)precision)) || (precision == -1 &&
						((flag == 2 && ft_evaluate_uint(t, dd.data) >= r)
						|| flag != 2)))
			return (ft_putchar_fdr('0', dd.fd));
	}
	return (0);
}

static size_t		ft_flags(t_bool h, char tt, int fd, t_bool *ss)
{
	if (*ss != TRUE && h != TRUE && ft_issigned(tt))
	{
		*ss = TRUE;
		return (ft_putchar_fdr(' ', fd));
	}
	return (0);
}

/*
** affiche les caracteres specifies par les flags en fonction du type demande
** valeur de renvoi :
** dans *flag : 1 si flag '-', 2 si flag '0', ret 0 sinon
** dans t.print : le nombre de caracteres ecrits.
** dans t.conv : le nombre de caracteres "passes"
*/

void				ft_flag(const char *s, uintmax_t data, int fd, int flag)
{
	const char		*t;
	t_bole			bb;
	t_datas			dd;

	bb.h = FALSE;
	t = ft_gettype(s);
	bb.tag = FALSE;
	bb.ss = FALSE;
	while (++s)
	{
		if (*s == '#')
		{
			dd.fd = fd;
			dd.data = data;
			ft_flagtag(s, dd, &bb.tag, flag);
		}
		else if (*s == '+')
			bb.h = TRUE;
		else if (*s == ' ')
			ft_whichsign(s, data) == 1 && ft_strchr(s, '+') == NULL
				&& ft_strchr(s, '+') < t ? ft_flags(bb.h, *t, fd, &bb.ss) : 0;
		else if (*s != '0' && *s != '-')
			break ;
	}
}

t_size				ft_flag0m(const char *s, uintmax_t data, int *flag)
{
	t_size			r;
	const char		*t;
	t_bole			bb;
	int				szm;

	ft_nln((intmax_t*)flag, 0) && ft_nln((intmax_t*)&r.conv, 0) &&
		ft_nln((intmax_t*)&r.print, 0) && ft_nln((intmax_t*)&bb.h, 0) &&
		ft_nln((intmax_t*)&bb.tag, 0) && ft_nln((intmax_t*)&bb.ss, 0);
	t = ft_gettype(s);
	while (++s && ++r.conv)
	{
		if (*s == '#')
			r.print += ft_flag_htag(s, &bb, data, flag);
		else if (*s == '+')
			(bb.h == FALSE && ft_nln((intmax_t*)&bb.h, 1) &&
			ft_nln((intmax_t*)&r.print, (ft_whichsign(s, data) ? 1 : 0)
				+ r.print));
		else if ((szm = ft_flag_szm(s, &bb, data, flag)) == -1)
			break ;
		else
			r.print += szm;
	}
	return (r);
}
