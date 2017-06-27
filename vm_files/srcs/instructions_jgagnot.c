/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_jgagnot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:38:15 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/27 15:47:43 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		_live(t_instruct *i)
{
	count_live(1, 0); // increment. du nbr de live
	get_champion()[i->args[0]].live = 1; // on met le live du champion a 1
	display_live(i->args[0], get_champion()); // on affiche le joueur vivant
	return (0);
}

int		_st(t_process *proc, t_instruct *instruct, char *arena)
{
	int		val;

	if (!is_valid_reg(instruct->args[0]))
		return (0);
	val = proc->reg[instruct->args[0] - 1];
	if (instruct->types[1] == T_REG)
	{
		if (!is_valid_reg(instruct->args[1]))
			return (0);
		proc->reg[instruct->args[1]] = val;
	}
	else
		store_at(arena, proc->pc + (instruct->args[1] % IDX_MOD), val);
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int		_add(t_process *proc, t_instruct *instruct)
{
	if (!is_valid_reg(instruct->args[0]) || !is_valid_reg(instruct->args[1])
		|| !is_valid_reg(instruct->args[2]))
		return (0);
	proc->reg[instruct->args[2] - 1] = proc->reg[instruct->args[0] - 1] +
	proc->reg[instruct->args[1] - 1];
	if (proc->reg[instruct->args[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}

int		_sub(t_process *proc, t_instruct *instruct)
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
