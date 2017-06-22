/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:11:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/06/22 20:08:02 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		is_valid_reg(int reg)
{
	if (reg < 1 || reg > 16)
		return (0);
	return (1);
}

int 	store_at(char *arena, int i, int val)
{
/*	*(arena + (i % MEM_SIZE)) = *val;
	*(arena + ((i + 1) % MEM_SIZE)) = *(val + 1);
	*(arena + ((i + 2) % MEM_SIZE)) = *(val + 2);
	*(arena + ((i + 3) % MEM_SIZE)) = *(val + 3);*/
	(void)arena;
	(void)i;
	(void)val;
	return (0);
}

int		extract_at(char *arena, int addr)
{
	int ret;

	ret = 0;
	ret = ret | *(arena + (addr++ % MEM_SIZE)) * (1 << 24);
	ret = ret | *(arena + (addr++ % MEM_SIZE)) * (1 << 16);
	ret = ret | *(arena + (addr++ % MEM_SIZE)) * (1 << 8);
	ret = ret | *(arena + (addr % MEM_SIZE));
	return (ret);
}

int		swap_32int(int num)
{
	return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000)
		| ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}
