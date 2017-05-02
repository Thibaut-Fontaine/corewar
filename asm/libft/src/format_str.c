/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:55 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void		format_str(va_list *args, t_specs *specs)
{
	char	*test;

	test = va_arg(*args, char *);
	if (test != 0)
		specs->data = ft_strdup(test);
	else
	{
		specs->data = ft_strdup("(null)");
		return ;
	}
	if (specs->precision && specs->precision < ft_strlen(specs->data))
		specs->data = ft_strcut(specs->data, specs->precision);
	if (specs->width && (specs->width > specs->precision
		|| specs->width > ft_strlen(specs->data)))
		specs->data = ft_strpad(specs->data, specs->width,
								(specs->minus ? 'l' : 'r'));
}
