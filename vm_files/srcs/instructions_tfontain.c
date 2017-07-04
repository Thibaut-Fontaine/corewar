/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tfontain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/04 23:22:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				_live(t_process *proc, t_instruct *i)
{
	if (i->args[0] > 0 && i->args[0] <= n_champ(0))
	{
		count_live(0);
		proc->exec_live = 1;
		*last_living_player() = i->args[0];
		display_live(i->args[0], get_champion());
	}
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}

int				_and(t_process *proc, t_instruct *i, char *arena)
{
	if ((*(int*)op_stock(proc, i, arena, 2) =
		(op_value(proc, i, arena, 0) & op_value(proc, i, arena, 1))) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}

int				_or(t_process *proc, t_instruct *i, char *arena)
{
	if ((*(int*)op_stock(proc, i, arena, 2) =
		(op_value(proc, i, arena, 0) | op_value(proc, i, arena, 1))) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}

int				_xor(t_process *proc, t_instruct *i, char *arena)
{
	if ((*(int*)op_stock(proc, i, arena, 2) =
		(op_value(proc, i, arena, 0) ^ op_value(proc, i, arena, 1))) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}

int				_zjmp(t_process *proc, t_instruct *i, char *arena)
{
	if (proc->carry == 1)
		proc->pc = (proc->pc + op_value(proc, i, arena, 0)) % MEM_SIZE;
	return (0);
}

int				_sti(t_process *proc, t_instruct *i, char *arena)
{
	int			tmp;

	if ((tmp = op_value(proc, i, arena, 1) + op_value(proc, i, arena, 2)
				% MEM_SIZE) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	arena[tmp] = op_value(proc, i, arena, 0);
	proc->pc = (proc->pc + i->size) % MEM_SIZE;
	return (0);
}
