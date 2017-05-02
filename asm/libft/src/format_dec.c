/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:52 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static void		get_arg(va_list *args, t_specs *specs)
{
	if (specs->length == 'l')
		specs->data = ft_itoa_base16(va_arg(*args, long), 10);
	else if (specs->length == 'L')
		specs->data = ft_itoa_base16(va_arg(*args, long long), 10);
	else if (specs->length == 'h')
		specs->data = ft_itoa_base16((short)va_arg(*args, int), 10);
	else if (specs->length == 'H')
		specs->data = ft_itoa_base16((signed char)va_arg(*args, int), 10);
	else if (specs->length == 'j')
		specs->data = ft_itoa_base16(va_arg(*args, intmax_t), 10);
	else if (specs->length == 'z')
		specs->data = ft_itoa_base16(va_arg(*args, ssize_t), 10);
	else
		specs->data = ft_itoa_base16(va_arg(*args, int), 10);
}

void			format_dec(va_list *args, t_specs *specs)
{
	char	*init;

	get_arg(args, specs);
	init = ft_strdup(specs->data);
	if (ft_ltoi(init) < 0)
		specs->data = strip_sign(specs->data);
	if (specs->precision > ft_strlen(specs->data))
		specs->data = handle_num_precision(specs->data, specs->precision);
	if (specs->width && specs->width > ft_strlen(specs->data))
		specs->data = ft_strpad(specs->data, specs->width,
							(specs->minus ? 'l' : 'r'));
	if (specs->zero && !specs->minus && !specs->precision)
		specs->data = ft_spacetozero(specs->data);
	if ((specs->space || specs->plus) && ft_ltoi(init) >= 0)
		handle_prefix(specs, (specs->plus ? '+' : ' '));
	if (ft_strchr(init, '-'))
		handle_prefix(specs, '-');
	free(init);
}
