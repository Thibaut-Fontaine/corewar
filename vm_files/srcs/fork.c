/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 02:58:39 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/19 02:59:18 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	op_fork(t_plst *self, t_plst **head, t_instruct *instruct)
{
	int npc;

	npc = mod(self->proc.pc + (instruct->args[0] % IDX_MOD), MEM_SIZE);
	fork_process(head, self, npc);
	self->proc.pc = (self->proc.pc + instruct->size) % MEM_SIZE;
	return (1);
}

int	op_lfork(t_plst *self, t_plst **head, t_instruct *instruct)
{
	int npc;

	npc = mod(self->proc.pc + instruct->args[0], MEM_SIZE);
	fork_process(head, self, npc);
	self->proc.pc = (self->proc.pc + instruct->size) % MEM_SIZE;
	return (1);
}
