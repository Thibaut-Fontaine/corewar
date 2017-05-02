/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:55 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void		format_wstr(va_list *args, t_specs *specs)
{
	wchar_t	*test;

	test = va_arg(*args, wchar_t *);
	if (test)
		specs->wdata = ft_wstrdup(test);
	else
	{
		specs->wdata = ft_wstrdup(L"(null)");
		return ;
	}
	if (specs->precision && specs->precision < ft_wstrlen(specs->wdata))
		specs->wdata = ft_wstrcut(specs->wdata, specs->precision);
	if (specs->width && (specs->width > specs->precision
		|| specs->width > ft_wstrlen(specs->wdata)))
		specs->wdata = ft_wstrpad(specs->wdata, specs->width,
								(specs->minus ? 'l' : 'r'));
}
