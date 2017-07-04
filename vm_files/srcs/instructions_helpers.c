/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:11:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/04 19:42:13 by tfontain         ###   ########.fr       */
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
		*(arena + ((i + offset) % MEM_SIZE)) = ref;
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

void	free_instruction(t_instruct *instruct)
{
	if (instruct)
	{
		free(instruct->args);
		free(instruct->types);
		free(instruct);
	}
}

int		count_live(int reset)
{
	static uint	live = 0;
	uint		tmp;

	tmp = live;
	if (reset)
		live = 0;
	else
		++live;
	return (tmp);
}

/*
** functions who returns the pt where to write in all case (can be IND or REG)
** or return a value to read (DIR, INT or REG)
*/

int		op_value(t_process *proc, t_instruct *i, char *arena, int n)
{
	if (i->types[n] == T_DIR)
		return (i->args[n]);
	if (i->args[n] <= 0)
		return (0);
	if (i->types[n] == T_REG)
	{
		if (!is_valid_reg(i->args[n]))
			return (0);
		return (proc->reg[i->args[n] - 1]);
	}
	if (i->types[n] == T_IND)
		return (*(arena + ((i->args[n] - 1 + proc->pc) % MEM_SIZE)));
	return (0);
}

void	*op_stock(t_process *proc, t_instruct *i, char *arena, int n)
{
	if (i->types[n] == T_DIR)
		return (NULL);
	if (i->args[n] <= 0)
		return (NULL);
	if (i->types[n] == T_REG)
	{
		if (!is_valid_reg(i->args[n]))
			return (NULL);
		return (proc->reg + i->args[n] - 1);
	}
	if (i->types[n] == T_IND)
		return (arena + ((i->args[n] - 1 + proc->pc) % MEM_SIZE));
	return (NULL);
}
