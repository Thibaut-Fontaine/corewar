/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_mperronc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:45:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/06/20 22:24:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int extract_at(char *arena, int addr)
{
	char *ptr;
	int ret;

	ret = 0;
	ptr = arena + addr;
	ret = ret | *ptr * (1 << 24);
	ret = ret | (*ptr + 1) * (1 << 16);
	ret = ret | (*ptr + 2) * (1 << 8);
	ret = ret | (*ptr + 3);
	return (ret);
}

int aff(t_process *proc, t_instruct *instruct)
{
	int reg_num;

	reg_num = instruct->args[0];
	if (reg_num < 1 || reg_num > REG_NUMBER)
		return (0);
	ft_putchar(((int)proc->reg[reg_num]) % 256);
	return (1);
}

int fork(t_plst *self, t_plst *head, t_instruct *instruct)
{
	int npc;

	npc = self->proc.pc + instruct->args[0] % IDX_MOD;
	fork_process(&head, self, npc);
	return (1);
}

int lfork(t_plst *self, t_plst *head, t_instruct *instruct)
{
	int npc;

	npc = self->proc.pc + instruct->args[0] % MEM_SIZE;
	fork_process(&head, self, npc);
	return (1);
}

int ld(t_process *proc, t_instruct *instruct, char *arena)
{
	int val;

	if (instruct->types[0] == T_DIR)
		val = instruct->args[0];
	else
		val = extract_at(arena, (proc->pc + instruct->args[0]) % IDX_MOD);
	proc->reg[instruct->args[1]] = val;
	if (!val)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int lld(t_process *proc, t_instruct *instruct, char *arena)
{
	int val;

	if (instruct->types[0] == T_DIR)
		val = instruct->args[0];
	else
		val = extract_at(arena, (proc->pc + instruct->args[0]) % MEM_SIZE);
	proc->reg[instruct->args[1]] = val;
	if (!val)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int ldi(t_process *proc, t_instruct *instruct, char *arena)
{
	int val1;
	int val2;

	if (instruct->types[0] == T_REG)
		val1 = (int) proc->reg[instruct->args[0]];
	else if (instruct->types[0] == T_DIR)
		val1 = instruct->args[0];
	else
		val1 = extract_at(arena, (proc->pc + instruct->args[0]) % IDX_MOD);
	if (instruct->types[1] == T_DIR)
		val2 = instruct->args[1];
	else
		val2 = extract_at(arena, (proc->pc + instruct->args[1]) % IDX_MOD);
	val1 = val1 + val2;
	proc->reg[instruct->args[2]] = val1;
	if (!val1)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int lldi(t_process *proc, t_instruct *instruct, char *arena)
{
	int val1;
	int val2;

	if (instruct->types[0] == T_REG)
		val1 = (int) proc->reg[instruct->args[0]];
	else if (instruct->types[0] == T_DIR)
		val1 = instruct->args[0];
	else
		val1 = extract_at(arena, (proc->pc + instruct->args[0]) % MEM_SIZE);
	if (instruct->types[1] == T_DIR)
		val2 = instruct->args[1];
	else
		val2 = extract_at(arena, (proc->pc + instruct->args[1]) % MEM_SIZE);
	val1 = val1 + val2;
	proc->reg[instruct->args[2]] = val1;
	if (!val1)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
