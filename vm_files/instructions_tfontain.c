/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/06/21 19:36:29 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** function who returns the pt where to write in all case (can be IND or REG)
*/

static int			swap_32int(int num)
{
	return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000)
		| ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}
int					op_value(t_process *proc, t_instruct *i, char *arena, int n)
{
	if (i->types[n] == T_REG)
	{
		if (i->args[n] > 16 || i->args[n] < 1)
			return (0);
		return (*(int*)(proc->reg[i->args[n] - 1]));
	}
	if (i->types[n] == T_IND)
		return (*(arena + ((i->args[n] - 1 + proc->pc) % MEM_SIZE)));
	if (i->types[n] == T_DIR)
	{
		return (i->args[n]);
	}
	return (0);
}

void				*op_stock(t_process *proc, t_instruct *i, char *arena, int n)
{
	if (i->types[n] == T_REG)
	{
		if (i->args[n] > 16 || i->args[n] < 1)
			return (NULL);
		return (proc->reg[i->args[n] - 1]);
	}
	if (i->types[n] == T_IND)
		return (arena + ((i->args[n] - 1 + proc->pc) % MEM_SIZE));
	if (i->types[n] == T_DIR) // on ne peut pas ecrire dans un direct, erreur
		return (NULL);
	return (NULL);
}

int					and(t_process *proc, t_instruct *i, char *arena)
{
	*(int*)op_stock(proc, i, arena, 3) =
		(op_value(proc, i, arena, 0) & op_value(proc, i, arena, 1));
	return (0);
}

int					or(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 | source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					xor(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 ^ source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					zjmp(t_process proc, int source)
{
	if (proc.carry == 1)
		proc.pc = (proc.pc + source) % MEM_SIZE;
	return (0);
}

int					ldi(t_process proc, int indirect_res, int *dest, char *arn)
{
	if ((*dest = *(int *)(&arn[(proc.pc + indirect_res) % MEM_SIZE])) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					sti(t_process proc, int *src, int indirect_res, char *arn)
{
	if ((*(int *)(&arn[(proc.pc + indirect_res) % MEM_SIZE]) = *src) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}
