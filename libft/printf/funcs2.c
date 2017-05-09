/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:50:07 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/25 21:55:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** ce magnifique fichier a pour but ultime d'entasser les morceaux de fonctions
** separes cruellement du reste de leur environnement naturel par la norme.
*/

size_t			ft_flagtag_calculate(const char *s)
{
	size_t		r;

	r = 0;
	while (s[r] == '#' || s[r] == '0' || s[r] == '-' || s[r] == '+'
			|| s[r] == ' ')
		++r;
	return (ft_atoi(s + r));
}

size_t			ft_flag_o(const char *s, const char *t, uintmax_t data,
		int *flag)
{
	int			p;
	size_t		rr;

	p = ft_getprecision(s, *t);
	if (!(data == 0 && p == -1))
	{
		if (data == 0 && p == 0)
			return (1);
		else
		{
			rr = ft_flagtag_calculate(s);
			if (p != -1)
			{
				if (ft_evaluate_uint(t, data) >= (size_t)p)
					return (1);
			}
			else
			{
				if ((*flag == 2 && ft_evaluate_uint(t, data)
							>= rr) || *flag != 2)
					return (1);
			}
		}
	}
	return (0);
}

int				ft_nln(intmax_t *n1, intmax_t n2)
{
	*n1 = n2;
	return (1);
}

size_t			ft_flag_htag(const char *s, t_bole *bb, uintmax_t data,
		int *flag)
{
	const char	*t;

	t = ft_gettype(s);
	if (bb->tag == FALSE)
	{
		bb->tag = TRUE;
		if ((*t == 'x' || *t == 'X') && data != 0)
			return (2);
		else if (*t == 'o')
			return (ft_flag_o(s, t, data, flag));
	}
	return (0);
}

int				ft_flag_szm(const char *s, t_bole *bb, uintmax_t data,
		int *flag)
{
	const char *t;

	t = ft_gettype(s);
	if (*s == ' ')
	{
		if (bb->ss == FALSE && ft_whichsign(s, data) == 1 && bb->h != TRUE
				&& ft_strchr(s, '+') == NULL && ft_strchr(s, '+') < t
				&& ft_issigned(*t))
		{
			bb->ss = TRUE;
			return (1);
		}
	}
	else if (*s == '0')
		*flag != 1 && (*flag = 2);
	else if (*s == '-')
		*flag = 1;
	else
		return (-1);
	return (0);
}
