/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/29 22:43:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

void		usage(void)
{
	ft_putstr("Usage: ./corewar");
	ft_putstr("[-d N -s N -v N | -b --stealth | -n --stealth] [-a]");
	ft_putstr("<champion1.cor> <...>\n");
}

void		bad_source_file(char *name)
{
	ft_putstr("Can't read source file ");
	ft_putendl(name);
}
