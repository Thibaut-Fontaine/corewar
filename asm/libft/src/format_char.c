/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static char	*get_arg(t_specs *specs, va_list *args)
{
	char	*tmp;

	tmp = ft_strnew(1);
	tmp[0] = (specs->percent ? '%' : (char)va_arg(*args, int));
	tmp[1] = 0;
	return (tmp);
}

void		format_char(va_list *args, t_specs *specs)
{
	specs->data = get_arg(specs, args);
	if (specs->data[0] == 0)
	{
		specs->nullchar = TRUE;
		specs->data[0] = 'a';
	}
	if (specs->width)
		specs->data = ft_strpad(specs->data, specs->width,
								(specs->minus ? 'l' : 'r'));
	if (specs->nullchar)
		*(ft_strchr(specs->data, 'a')) = 0;
}
