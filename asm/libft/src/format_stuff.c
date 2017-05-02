/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:58 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static void	format_second(va_list *args, t_specs *specs)
{
	if (specs->type == 'o')
		format_oct(args, specs);
	else if (specs->type == 'd')
		format_dec(args, specs);
	else if (specs->type == 'u')
		format_udec(args, specs);
}

size_t		format_stuff(va_list *args, t_specs *specs)
{
	if (specs->type == 'c')
	{
		if (specs->length == 'l')
			format_wchar(args, specs);
		else
		{
			format_char(args, specs);
			return (ft_max2(1, ft_strlen(specs->data) + specs->nullchar));
		}
	}
	else if (specs->type == 'x' || specs->type == 'X' || specs->type == 'p')
		format_hex(args, specs);
	else if (specs->type == 's')
	{
		if (specs->length == 'l')
			format_wstr(args, specs);
		else
			format_str(args, specs);
	}
	else
		format_second(args, specs);
	if (specs->data)
		return (ft_strlen(specs->data));
	else
		return (0);
}
