/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:47:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 03:24:45 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** call the good function for the current operation to do,
** then += something to the pc of the process
*/

int			exec_instruction(char *arena, t_process proc, t_plst *head)
{
	(void)arena;
	(void)proc;
	if (proc.instruct->opcode == 1)
		live(proc, head, 42);
	if (proc.instruct->opcode == 2)
		ld();
	if (proc.instruct->opcode == 3)
		st();
	if (proc.instruct->opcode == 4)
		add();
	if (proc.instruct->opcode == 5)
		sub();
	if (proc.instruct->opcode == 6)
		and();
	if (proc.instruct->opcode == 7)
		or();
	if (proc.instruct->opcode == 8)
		xor();
	if (proc.instruct->opcode == 9)
		zjmp();
	if (proc.instruct->opcode == 10)
		ldi();
	if (proc.instruct->opcode == 11)
		sti();
	if (proc.instruct->opcode == 12)
		fork();
	if (proc.instruct->opcode == 13)
		lld();
	if (proc.instruct->opcode == 14)
		lldi();
	if (proc.instruct->opcode == 15)
		lfork();
	if (proc.instruct->opcode == 16)
		aff();
	return (0);
}

/*
** see which opcode it is, and return the function for it.

int			(*opcode(char *arena, t_process current))()
{
	return (NULL); // a faire
}
*/
