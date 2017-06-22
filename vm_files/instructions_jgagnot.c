/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_jgagnot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:38:15 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/22 18:03:15 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_valid_reg(int reg)
{
	if (reg < 1 || reg > 16)
		return (0);
	return (1);
}

int 	store_at(char *arena, int i, char *val)
{
	*(arena + (i % MEM_SIZE)) = *val;
	*(arena + ((i + 1) % MEM_SIZE)) = *(val + 1);
	*(arena + ((i + 2) % MEM_SIZE)) = *(val + 2);
	*(arena + ((i + 3) % MEM_SIZE)) = *(val + 3);
	return (0);
}

int		st(t_process *proc, t_instruct *instruct, char *arena)
{
	int		val;

	if (!is_valid_reg(instruct->args[0]))
		return (0);
	val = (int)proc->reg[instruct->args[0] - 1];
	if (instruct->types[1] == T_REG)
	{
		if (!is_valid_reg(instruct->args[1]))
			return (0);
		proc->reg[instruct->args[1]] = val;
	}
	else
		store_at(arena, proc->pc + (instruct->args[1] % IDX_MOD), (char*)val);
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int		add(t_process *proc, t_instruct *instruct)
{
	if (!is_valid_reg(instruct->args[0]) || !is_valid_reg(instruct->args[1])
		|| !is_valid_reg(instruct->args[2]))
		return (0);
	proc->reg[instruct->args[2] - 1] = (int)proc->reg[instruct->args[0] - 1] +
	proc->reg[instruct->args[1] - 1];
	if (proc->reg[instruct->args[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int		sub(t_process *proc, t_instruct *instruct)
{
	if (!is_valid_reg(instruct->args[0]) || !is_valid_reg(instruct->args[1])
		|| !is_valid_reg(instruct->args[2]))
		return (0);
	proc->reg[instruct->args[2] - 1] = proc->reg[instruct->args[0] - 1] -
	proc->reg[instruct->args[1] - 1];
	if (proc->reg[instruct->args[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
