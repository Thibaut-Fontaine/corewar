/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:17:25 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/27 15:23:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		select_process_and_execute2(t_plst *p_current, t_plst **p_head,
		char *arena, char *color)
{
	if (p_current->proc.instruct->opcode == 0x08)
		op_xor(&p_current->proc, p_current->proc.instruct, arena);
	else if (p_current->proc.instruct->opcode == 0x09)
		op_zjmp(&p_current->proc, arena);
	else if (p_current->proc.instruct->opcode == 0x0A)
		op_ldi(&p_current->proc, p_current->proc.instruct, arena);
	else if (p_current->proc.instruct->opcode == 0x0B)
		op_sti(&p_current->proc, p_current->proc.instruct, arena, color);
	else if (p_current->proc.instruct->opcode == 0x0C)
		op_fork(p_current, p_head, p_current->proc.instruct);
	else if (p_current->proc.instruct->opcode == 0x0D)
		op_lld(&p_current->proc, p_current->proc.instruct, arena);
	else if (p_current->proc.instruct->opcode == 0x0E)
		op_lldi(&p_current->proc, p_current->proc.instruct, arena);
	else if (p_current->proc.instruct->opcode == 0x0F)
		op_lfork(p_current, p_head, p_current->proc.instruct);
	else if (p_current->proc.instruct->opcode == 0x10)
		op_aff(&p_current->proc, p_current->proc.instruct);
	return (0);
}

static int		select_process_and_execute(t_plst *p_current, t_plst **p_head,
		char *arena, char *color)
{
	if (p_current->proc.instruct->opcode == 0x01)
		op_live(&p_current->proc, p_current->proc.instruct);
	else if (p_current->proc.instruct->opcode == 0x02)
		op_ld(&p_current->proc, p_current->proc.instruct, arena);
	else if (p_current->proc.instruct->opcode == 0x03)
		op_st(&p_current->proc, p_current->proc.instruct, arena, color);
	else if (p_current->proc.instruct->opcode == 0x04)
		op_add(&p_current->proc, p_current->proc.instruct);
	else if (p_current->proc.instruct->opcode == 0x05)
		op_sub(&p_current->proc, p_current->proc.instruct);
	else if (p_current->proc.instruct->opcode == 0x06)
		op_and(&p_current->proc, p_current->proc.instruct, arena);
	else if (p_current->proc.instruct->opcode == 0x07)
		op_or(&p_current->proc, p_current->proc.instruct, arena);
	return (select_process_and_execute2(p_current, p_head, arena, color));
}

static void		execute_one_process(t_plst *curr, t_plst **head, t_argv *info)
{
	if (!curr->proc.instruct)
	{
		if (!(curr->proc.instruct =
			check_operation(info->arena, &curr->proc, info->ref_tab)))
		{
			curr->proc.pc = (curr->proc.pc + 1) % MEM_SIZE;
			return ;
		}
	}
	if (curr->proc.wait > 0)
		--curr->proc.wait;
	else if (curr->proc.wait == 0)
	{
		select_process_and_execute(curr, head, info->arena, info->color);
		free_instruction(curr->proc.instruct);
		if ((curr->proc.instruct =
			check_operation(info->arena, &curr->proc, info->ref_tab)))
			--curr->proc.wait;
	}
	else
		curr->proc.pc = (curr->proc.pc + 1) % MEM_SIZE;
}

void			execute_all_process(t_plst **head, t_argv *info)
{
	t_plst		*p;

	p = *head;
	while (p)
	{
		execute_one_process(p, head, info);
		p = p->nxt;
	}
}
