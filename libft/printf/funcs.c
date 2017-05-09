/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:58:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/24 18:18:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** return 1 if the conversion is signed, take the conversion char in the format
*/

int			ft_issigned(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (1);
	return (0);
}

int			ft_whichsign(const char *s, intmax_t i)
{
	s = ft_gettype(s);
	if (*s == 'D')
		return ((long int)i >= 0);
	if (*(s - 1) == 'h')
	{
		if (*(s - 2) == 'h')
			return ((char)i >= 0);
		else
			return ((short int)i >= 0);
	}
	if (*(s - 1) == 'l' || *(s - 1) == 'j' || *(s - 1) == 'z')
		return ((long int)i >= 0);
	return ((int)i >= 0);
}

size_t		ft_putnc(char c, size_t i, int fd)
{
	size_t	ret;

	ret = 0;
	while (i--)
		ret += ft_putchar_fdr(c, fd);
	return (ret);
}

void		ft_fflag(const char *s, int flag, t_datas dd, int testflag)
{
	const char *type;

	type = ft_gettype(s);
	if (flag == testflag && (*type == 'd' || *type == 'D' || *type == 'i')
			&& ft_whichsign(s, dd.data) == 0)
		ft_putchar_fdr('-', dd.fd);
	if (flag == testflag && (*type == 'd' || *type == 'D' || *type == 'i')
			&& ft_whichsign(s, dd.data) == 1 && ft_strchr(s, '+') != NULL
			&& ft_strchr(s, '+') < type)
		ft_putchar_fdr('+', dd.fd);
	if (flag == testflag && (*type == 'x' || *type == 'X') && dd.data != 0
			&& ft_strchr(s, '#') != NULL && ft_strchr(s, '#') < type)
	{
		ft_putchar_fdr('0', dd.fd);
		ft_putchar_fdr(*type, dd.fd);
	}
}

int			ft_pourcent(const char *format, size_t *r, size_t *i, int fd)
{
	char	*chr;
	size_t	len;
	t_size	t;

	if ((chr = ft_strchr(format + *i + 1, '%')) != NULL
			&& chr < ft_gettype(format + *i))
	{
		len = chr - (format + *i);
		chr = ft_memdup(format + *i, len);
		chr[len + 1] = '\0';
		chr[len] = 'c';
		t = ft_convert_print(chr, '%', fd);
		free(chr);
		*r += t.print;
		*i += t.conv;
		return (0);
	}
	return (1);
}
