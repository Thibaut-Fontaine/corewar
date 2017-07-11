/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tfontain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/11 18:17:43 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				_zjmp(t_process *proc, char *arena)
{
	if (proc->carry == 1)
		proc->pc = (proc->pc + op_value(proc, arena, 0, 0)) % MEM_SIZE;
	return (0);
}

int				_sti(t_process *proc, t_instruct *i, char *arena)
{
	int			n;

	if (i->types[1] == T_REG)
	{
		if (!is_valid_reg(i->args[1]))
		{
			proc->pc = (proc->pc + i->size) % MEM_SIZE;
			return (0);
		}
		n = proc->reg[i->args[1] - 1];
	}
	else if (i->types[1] == T_IND)
		n = extract_at(arena, proc->pc + (i->args[1] % IDX_MOD));
	else
		n = i->args[1];
	if (i->types[2] == T_IND)
		n += arena[i->args[2]];
	else
		n += i->args[2];

	store_at(arena, n, proc->reg[i->args[0] - 1]);
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (1);
}
