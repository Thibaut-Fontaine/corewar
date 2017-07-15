/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_and_or_xor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:41:38 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/15 08:20:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				_and(t_process *proc, t_instruct *i, char *arena)
{
	if (!is_valid_reg(i->args[2]))
	{
		proc->pc = (proc->pc + i->size) % MEM_SIZE;
		return (0);
	}
	proc->reg[i->args[2] - 1] = op_value(proc, arena, 0, 1)
		& op_value(proc, arena, 1, 1);
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	proc->carry = (proc->reg[i->args[2] - 1] ? 0 : 1);
	return (0);
}

int				_or(t_process *proc, t_instruct *i, char *arena)
{
	if (!is_valid_reg(i->args[2]))
	{
		proc->pc = (proc->pc + i->size) % MEM_SIZE;
		return (0);
	}
	proc->reg[i->args[2] - 1] = op_value(proc, arena, 0, 1)
		| op_value(proc, arena, 1, 1);
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	proc->carry = (proc->reg[i->args[2] - 1] ? 0 : 1);
	return (0);
}

int				_xor(t_process *proc, t_instruct *i, char *arena)
{
	if (!is_valid_reg(i->args[2]))
	{
		proc->pc = (proc->pc + i->size) % MEM_SIZE;
		return (0);
	}
	proc->reg[i->args[2] - 1] = op_value(proc, arena, 0, 1)
		^ op_value(proc, arena, 1, 1);
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	proc->carry = (proc->reg[i->args[2] - 1] ? 0 : 1);
	return (0);
}
