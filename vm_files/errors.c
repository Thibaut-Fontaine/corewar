/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:50:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/28 20:34:54 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

void		usage(void)
{
	ft_putendl("Usage : ./corewar <champion1.cor> <...>\n");
}

void		bad_source_file(char *name)
{
	ft_putendl("Can't read source file");
	ft_putendl(name);
	ft_putchar('\n');
}
