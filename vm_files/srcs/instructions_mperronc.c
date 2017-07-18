/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_mperronc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:45:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/18 18:02:14 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int _aff(t_process *proc, t_instruct *instruct)
{
	int reg_num;

	reg_num = instruct->args[0];
	if (reg_num < 1 || reg_num > REG_NUMBER)
		return (0);
	if ((*flags() & _N_) == 0)
		ft_putchar(proc->reg[reg_num - 1] % 256);
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	return (1);
}

int _fork(t_plst *self, t_plst **head, t_instruct *instruct)
{
	int npc;

	npc = mod(self->proc.pc + (instruct->args[0] % IDX_MOD), MEM_SIZE);
	fork_process(head, self, npc);
	self->proc.pc = (self->proc.pc + instruct->size) % MEM_SIZE;
	return (1);
}

int _lfork(t_plst *self, t_plst **head, t_instruct *instruct)
{
	int npc;

	npc = mod(self->proc.pc + instruct->args[0], MEM_SIZE);
	fork_process(head, self, npc);
	self->proc.pc = (self->proc.pc + instruct->size) % MEM_SIZE;
	return (1);
}

int _ld(t_process *proc, t_instruct *instruct, char *arena)
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

int _lld(t_process *proc, t_instruct *instruct, char *arena)
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

int _ldi(t_process *proc, t_instruct *instruct, char *arena)
{
	int val;

	if (!is_valid_reg(instruct->args[2]))
	{
		proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
		return (0);
	}
	if (instruct->types[0] == T_REG)
	{
		if (!is_valid_reg(instruct->args[0]))
		{
			proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
			return (0);
		}
		val = proc->reg[instruct->args[0] - 1];
	}
	else if (instruct->types[0] == T_DIR)
		val = instruct->args[0];
	else
		val = extract_at(arena, proc->pc + (instruct->args[0] % IDX_MOD));
	if (instruct->types[1] == T_DIR)
		val += instruct->args[1];
	else
		val += extract_at(arena, proc->pc + (instruct->args[1] % IDX_MOD));
	proc->reg[instruct->args[2] - 1] =
		extract_at(arena, proc->pc + (val % IDX_MOD));
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (proc->reg[instruct->args[2] - 1] ? 0 : 1);
	return (1);
}

int _lldi(t_process *proc, t_instruct *instruct, char *arena)
{
	int val;

	if (instruct->args[1] < 1 || instruct->args[1] > REG_NUMBER)
	{
		proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
		return (0);
	}
	if (instruct->types[0] == T_REG)
		val = proc->reg[instruct->args[0]];
	else if (instruct->types[0] == T_DIR)
		val = instruct->args[0];
	else
		val = extract_at(arena, proc->pc + instruct->args[0]);
	if (instruct->types[1] == T_DIR)
		val += instruct->args[1];
	else
		val += extract_at(arena, proc->pc + instruct->args[1]);
	proc->reg[instruct->args[2] - 1] = val;
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->carry = (val ? 0 : 1);
	return (1);
}
