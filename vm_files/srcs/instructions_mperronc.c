/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_mperronc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:45:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/24 19:04:21 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	op_aff(t_process *proc, t_instruct *instruct)
{
	int reg_num;

	reg_num = instruct->args[0];
	if (reg_num < 1 || reg_num > REG_NUMBER)
		return (0);
	if ((*flags() & _G_) == 0)
		ft_putchar(proc->reg[reg_num - 1] % 256);
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	return (1);
}

int	op_ld(t_process *proc, t_instruct *instruct, char *arena)
{
	int val;

	if (!is_valid_reg(instruct->args[1]))
	{
		proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
		return (0);
	}
	if (instruct->types[0] == T_DIR)
		val = instruct->args[0];
	else
		val = extract_at(arena, proc->pc + (instruct->args[0] % IDX_MOD));
	proc->reg[instruct->args[1] - 1] = val;
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (val ? 0 : 1);
	return (1);
}

int	op_lld(t_process *proc, t_instruct *instruct, char *arena)
{
	int val;

	if (!is_valid_reg(instruct->args[1]))
	{
		proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
		return (0);
	}
	if (instruct->types[0] == T_DIR)
		val = instruct->args[0];
	else
		val = extract_at(arena, proc->pc + instruct->args[0]);
	proc->reg[instruct->args[1] - 1] = val;
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (val ? 0 : 1);
	return (1);
}

int	op_ldi(t_process *proc, t_instruct *i, char *arena)
{
	int val;

	if ((i->types[1] == T_REG && !is_valid_reg(i->args[1]))
		|| !is_valid_reg(i->args[2]))
		return (proc->pc = (proc->pc + i->size) % MEM_SIZE);
	if (i->types[0] == T_REG)
	{
		if (!is_valid_reg(i->args[0]))
			return (proc->pc = (proc->pc + i->size) % MEM_SIZE);
		val = proc->reg[i->args[0] - 1];
	}
	else if (i->types[0] == T_DIR)
		val = i->args[0];
	else
		val = extract_at(arena, proc->pc + (i->args[0] % IDX_MOD));
	if (i->types[1] == T_REG)
		val += proc->reg[i->args[1] - 1];
	else
		val += i->args[1];
	proc->reg[i->args[2] - 1] = extract_at(arena, proc->pc + (val % IDX_MOD));
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (1);
}

int	op_lldi(t_process *proc, t_instruct *i, char *arena)
{
	int val;

	if ((i->types[1] == T_REG && !is_valid_reg(i->args[1]))
		|| !is_valid_reg(i->args[2]))
		return (proc->pc = (proc->pc + i->size) % MEM_SIZE);
	if (i->types[0] == T_REG)
	{
		if (!is_valid_reg(i->args[0]))
			return (proc->pc = (proc->pc + i->size) % MEM_SIZE);
		val = proc->reg[i->args[0] - 1];
	}
	else if (i->types[0] == T_DIR)
		val = i->args[0];
	else
		val = extract_at(arena, proc->pc + i->args[0]);
	if (i->types[1] == T_REG)
		val += proc->reg[i->args[1] - 1];
	else
		val += i->args[1];
	proc->reg[i->args[2] - 1] = extract_at(arena, proc->pc + val);
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	proc->carry = (val ? 0 : 1);
	return (1);
}
