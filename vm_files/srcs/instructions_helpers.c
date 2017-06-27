/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:11:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/06/27 16:35:52 by jgagnot          ###   ########.fr       */
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
	int		offset;
	int 	ref;

	offset = 0;
	ref = val;
	while (offset < 4)
	{
		ref = val << offset * 8;
		ref = ref >> 3 * 8;
		*(arena + (i % MEM_SIZE)) = ref;
		i++;
		offset ++;
	}
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
