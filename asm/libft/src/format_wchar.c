/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static wchar_t	*get_arg(t_specs *specs, va_list *args)
{
	wchar_t	*tmp;

	tmp = ft_wstrnew(sizeof(wchar_t) * 2);
	tmp[0] = (specs->percent ? L'%' : (wchar_t)va_arg(*args, int));
	tmp[1] = 0;
	return (tmp);
}

void			format_wchar(va_list *args, t_specs *specs)
{
	specs->wdata = get_arg(specs, args);
	if (specs->wdata[0] == 0)
	{
		specs->nullchar = TRUE;
		specs->wdata[0] = L'a';
	}
	if (specs->width)
		specs->wdata = ft_wstrpad(specs->wdata, specs->width,
								(specs->minus ? 'l' : 'r'));
	if (specs->nullchar)
		*(ft_wstrchr(specs->wdata, L'a')) = 0;
}
