/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:05 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static const char	*inner_printf(t_specs *specs, const char *restrict format,
							size_t *count, va_list *args)
{
	init_specs(specs);
	format = parse_specs(format, specs);
	if (specs->valid)
	{
		*count += format_stuff(args, specs);
		if (specs->wdata)
		{
			*count += ft_putwstr(specs->wdata);
			free(specs->wdata);
		}
		else if (specs->data)
		{
			ft_putstr(specs->data);
			free(specs->data);
		}
	}
	else
	{
		ft_putchar(*format);
		format++;
		*count += 1;
	}
	return (format);
}

int					ft_printf(const char *restrict format, ...)
{
	size_t		count;
	t_specs		*specs;
	va_list		args;

	specs = malloc(sizeof(t_specs));
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			count++;
		}
		else
			format = inner_printf(specs, format, &count, &args);
	}
	free(specs);
	va_end(args);
	return (count);
}
