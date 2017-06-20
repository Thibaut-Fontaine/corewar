/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:57:07 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/20 16:57:08 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include "./error.h"

void		too_many_champions(void)
{
	ft_putstr("Too many champions\n");
	exit(-1);
}

void		champion_too_small(const char *name)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" is too small to be a champion\n");
	exit(-1);
}

void		champion_too_big(const char *name, unsigned int len)
{
	ft_putstr("Error: File ");
	ft_putstr(name);
	ft_putstr(" has too large a code (");
	ft_putnbr(len);
	ft_putstr(" bytes > ");
	ft_putnbr(CHAMP_MAX_SIZE);
	ft_putstr(" bytes)\n");
	exit(-1);
}
