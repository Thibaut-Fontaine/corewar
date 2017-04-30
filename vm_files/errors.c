/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/30 04:36:15 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

void		usage(void)
{
	ft_putstr("Usage: ./corewar");
	ft_putstr("[-d N -s N -v N | -b --stealth | -n --stealth] [-a]");
	ft_putstr("<champion1.cor> <...>\n");
	exit(-1);
}

void		bad_source_file(const char *name)
{
	ft_putstr("Can't read source file ");
	ft_putendl(name);
	exit(-1);
}

void		bad_magic_number(const char *name)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" has an invalid header\n");
	exit(-1);
}

void		close_error(const char *name)
{
	ft_putstr("Error while closing the file ");
	ft_putendl(name);
	exit(-1);
}
