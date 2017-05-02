/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:53 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static void		get_arg(va_list *args, t_specs *specs)
{
	if (specs->length == 'l')
		specs->data = ft_uitoa_base16(va_arg(*args, unsigned long), 16);
	else if (specs->length == 'L')
		specs->data = ft_uitoa_base16(va_arg(*args, unsigned long long), 16);
	else if (specs->length == 'h')
		specs->data = ft_uitoa_base16((unsigned short)va_arg(*args, int), 16);
	else if (specs->length == 'H')
		specs->data = ft_uitoa_base16((unsigned char)va_arg(*args, int), 16);
	else if (specs->length == 'j')
		specs->data = ft_uitoa_base16(va_arg(*args, uintmax_t), 16);
	else if (specs->length == 'z')
		specs->data = ft_uitoa_base16(va_arg(*args, size_t), 16);
	else
		specs->data = ft_uitoa_base16(va_arg(*args, unsigned int), 16);
}

void			format_hex(va_list *args, t_specs *specs)
{
	get_arg(args, specs);
	if (specs->precision > ft_strlen(specs->data))
		specs->data = handle_num_precision(specs->data, specs->precision);
	if (specs->width && specs->width > ft_strlen(specs->data) +
		((specs->sharp || specs->pointer) ? 2 : 0))
		specs->data = ft_strpad(specs->data, specs->width,
							(specs->minus ? 'l' : 'r'));
	if (specs->zero && !specs->minus && !specs->precision)
		specs->data = ft_spacetozero(specs->data);
	if ((specs->sharp && ft_atoi(specs->data) != 0) || specs->type == 'p')
		handle_prefix_x(specs);
	if (specs->type == 'X')
		specs->data = ft_strtoupper(specs->data);
}
