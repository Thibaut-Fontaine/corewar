/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tfontain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/06/23 22:57:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** functions who returns the pt where to write in all case (can be IND or REG)
** or return a value to read (DIR, INT or REG)
*/

int				op_value(t_process *proc, t_instruct *i, char *arena, int n)
{
	if (i->types[n] == T_REG)
	{
		if (!is_valid_reg(i->args[n]))
			return (0);
		return (proc->reg[i->args[n] - 1]);
	}
	if (i->types[n] == T_IND)
		return (*(arena + ((i->args[n] - 1 + proc->pc) % MEM_SIZE)));
	if (i->types[n] == T_DIR)
		return (i->args[n]);
	return (0);
}

void			*op_stock(t_process *proc, t_instruct *i, char *arena, int n)
{
	if (i->types[n] == T_REG)
	{
		if (!is_valid_reg(i->args[n]))
			return (NULL);
		return (proc->reg + i->args[n] - 1);
	}
	if (i->types[n] == T_IND)
		return (arena + ((i->args[n] - 1 + proc->pc) % MEM_SIZE));
	if (i->types[n] == T_DIR) // on ne peut pas ecrire dans un direct, ->erreur
		return (NULL);
	return (NULL);
}

int				and(t_process *proc, t_instruct *i, char *arena)
{
	if ((*(int*)op_stock(proc, i, arena, 2) =
		(op_value(proc, i, arena, 0) & op_value(proc, i, arena, 1))) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (0);
}

int				or(t_process *proc, t_instruct *i, char *arena)
{
	if ((*(int*)op_stock(proc, i, arena, 2) =
		(op_value(proc, i, arena, 0) | op_value(proc, i, arena, 1))) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (0);
}

int				xor(t_process *proc, t_instruct *i, char *arena)
{
	if ((*(int*)op_stock(proc, i, arena, 2) =
		(op_value(proc, i, arena, 0) ^ op_value(proc, i, arena, 1))) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (0);
}

int				zjmp(t_process *proc, t_instruct *i, char *arena)
{
	if (proc->carry == 1)
		proc->pc = (proc->pc + op_value(proc, i, arena, 0)) % MEM_SIZE;
	return (0);
}

int				sti(t_process *proc, t_instruct *i, char *arena)
{
	int			tmp;

	if ((tmp = op_value(proc, i, arena, 1) + op_value(proc, i, arena, 2)
				% MEM_SIZE) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	arena[tmp] = op_value(proc, i, arena, 0);
	return (0);
}
