/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:29:39 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/25 02:42:40 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** toutes les fonctions d'ecriture presentes retournent le nombre de caracteres
** ecrits, -1 si erreur (si write retourne -1) ou si le format est non specifie
** le type de retour est donc ssize_t (4 bytes signe)
** -
** see also the folder ./put_funcs/
*/

const char			*ft_gettype(const char *s)
{
	size_t			n;

	n = 0;
	while (s[n] && s[n] != 's' && s[n] != 'S' && s[n] != 'p' && s[n] != 'd' &&
			s[n] != 'D' && s[n] != 'i' && s[n] != 'o' && s[n] != 'O' &&
			s[n] != 'u' && s[n] != 'U' && s[n] != 'x' && s[n] != 'X' &&
			s[n] != 'c' && s[n] != 'C')
		++n;
	return (s + n);
}

/*
** renvoie un pointeur sur fonction de type ssize_t()
** du genre :
**				ssize_t ft_putuint32_fd(uint32_t i, int fd);
*/

ssize_t				(*ft_typeinteger(const char *f))(uintmax_t d, int fd)
{
	if (*f == 'U' || *f == 'u')
		return (&ft_putuint_fdr);
	if (*f == 'o' || *f == 'O')
		return (&ft_putoct_fdr);
	if (*f == 'x')
		return (&ft_puthex_fdr);
	if (*f == 'X')
		return (&ft_puthexx_fdr);
	else
		return ((void*)&ft_putint_fdr);
}

/*
** renvoie le pt sur fonction correspondant au type et au modif. de longueur
*/

ssize_t				(*ft_type(const char *f))(uintmax_t d, int fd)
{
	if (*f == 'S' || (*f == 's' && *(f - 1) == 'l'))
		return ((void*)&ft_putwstr_fdr);
	if (*f == 's')
		return ((void*)&ft_putstr_fdr);
	if (*f == 'C' || (*f == 'c' && *(f - 1) == 'l'))
		return ((void*)&ft_putwchar_fdr);
	if (*f == 'c')
		return ((void*)&ft_putchar_fdr);
	if (*f == 'd' || *f == 'i' || *f == 'D' || *f == 'U' || *f == 'u'
			|| *f == 'o' || *f == 'O' || *f == 'x' || *f == 'X')
		return (ft_typeinteger(f));
	if (*f == 'p')
		return ((void*)&ft_putadr_fdr);
	return (NULL);
}

static ssize_t		ft_printstring(const char *t, uintmax_t data, int fd,
		int precision)
{
	if (*t == 'S' || *t == 's')
	{
		if (*t == 's' && *(t - 1) != 'l')
		{
			if (data == 0)
				data = (uintmax_t)"(null)";
			if (precision != -1)
				return (ft_putnstr_fdr((char*)data, precision, fd));
			return (ft_putstr_fdr((char*)data, fd));
		}
		if (data == 0)
			data = (uintmax_t)L"(null)";
		if (precision != -1)
			return (ft_putnwstr_fdr((wchar_t*)data, precision, fd));
		return (ft_putwstr_fdr((wchar_t*)data, fd));
	}
	return (ft_type(t)(data, fd));
}

/*
** faire un cast specifique a chaque longueur
** ne pas gerer la precison si == -1
*/

ssize_t				ft_printdata(const char *t, uintmax_t data, int fd,
		int precision)
{
	ssize_t			ret;

	ret = 0;
	if (*t == 'U' || *t == 'u' || *t == 'o' || *t == 'O' || *t == 'x'
			|| *t == 'X')
	{
		if (precision == 0 && data == 0)
			return (0);
		if (precision != -1)
			ft_putnc('0', precision > (ret = ft_evaluate_uint(t, data))
					? precision - ret : 0, fd);
		return (precision > (ret = ft_typeuint(t, data, fd)) ?
				precision : ret);
	}
	else if (*t == 'd' || *t == 'i' || *t == 'D')
	{
		if (precision == 0 && data == 0)
			return (0);
		if (precision != -1)
			ft_putnc('0', precision > (ret = ft_evaluate_int(t, data)
						- !ft_whichsign(t, data)) ? precision - ret : 0, fd);
		return (precision > (ret = ft_typeint(t, data, fd)) ? precision : ret);
	}
	return (ft_printstring(t, data, fd, precision));
}
