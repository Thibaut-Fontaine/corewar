/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_jgagnot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:38:15 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/01 05:11:41 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		_live(t_process *proc, t_instruct *i)
{
	count_live(0);
	if (i->args[0] > 0 && i->args[0] < n_champ(0))
	{
		get_champion()[i->args[0] - 1].live = 1;
		display_live(i->args[0], get_champion());
	}
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}

int		_st(t_process *proc, t_instruct *instruct, char *arena)
{
	int		val;

	if (!is_valid_reg(instruct->args[0]))
	{
		proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
		return (0);
	}
	val = proc->reg[instruct->args[0] - 1];
	if (instruct->types[1] == T_REG)
	{
		if (!is_valid_reg(instruct->args[1]))
		{
			proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
			return (0);
		}
		proc->reg[instruct->args[1]] = val;
	}
	else
		store_at(arena, proc->pc + (instruct->args[1] % IDX_MOD), val);
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (val ? 0 : 1);
	return (1);
}

int		_add(t_process *proc, t_instruct *instruct)
{
	if (!is_valid_reg(instruct->args[0]) || !is_valid_reg(instruct->args[1])
		|| !is_valid_reg(instruct->args[2]))
	{
		proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
		return (0);
	}
	proc->reg[instruct->args[2] - 1] = proc->reg[instruct->args[0] - 1] +
	proc->reg[instruct->args[1] - 1];
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (proc->reg[instruct->args[2]] ? 1 : 0);
	return (1);
}

int		_sub(t_process *proc, t_instruct *instruct)
{
	if (!is_valid_reg(instruct->args[0]) || !is_valid_reg(instruct->args[1])
		|| !is_valid_reg(instruct->args[2]))
		{
			proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
			return (0);
		}
	proc->reg[instruct->args[2] - 1] = proc->reg[instruct->args[0] - 1] -
	proc->reg[instruct->args[1] - 1];
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (proc->reg[instruct->args[2]] ? 1 : 0);
	return (1);
}
