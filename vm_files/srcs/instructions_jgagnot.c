/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_jgagnot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:38:15 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/16 16:11:06 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** live read on negative numbers
*/

int		_live(t_process *proc, t_instruct *i)
{
	i->args[0] = -i->args[0];
	count_live(0);
	proc->exec_live = 1;
	if (i->args[0] > 0 && i->args[0] <= n_champ(0))
	{
		*last_living_player() = i->args[0];
		display_live(i->args[0], get_champion());
	}
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}

int		_st(t_process *proc, t_instruct *instruct, char *arena, char *color)
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
		proc->reg[instruct->args[1] - 1] = val;
	}
	else
	{
		store_at(arena, proc->pc + (instruct->args[1] % IDX_MOD), val);
		if (*flags() & _N_)
			write_color(color, proc->pc + (instruct->args[1] % IDX_MOD), proc->id);
	}
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
	proc->carry = (proc->reg[instruct->args[2] - 1] ? 0 : 1);
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
	proc->carry = (proc->reg[instruct->args[2] - 1] ? 0 : 1);
	return (1);
}
