/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/06/28 09:29:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** func to check the number of call to live
*/


static int		select_process_and_execute(t_plst *p_current, t_plst *p_head, char *arena)
{
	if (p_current->proc.instruct->opcode == 0x01)
		_live(p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x02)
		_ld(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x03)
		_st(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x04)
		_add(&p_current->proc, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x05)
		_sub(&p_current->proc, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x06)
		_and(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x07)
		_or(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x08)
		_xor(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x09)
		_zjmp(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0A)
		_ldi(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0B)
		_sti(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0C)
		_fork(p_current, p_head, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x0D)
		_lld(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0E)
		_lldi(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0F)
		_lfork(p_current, p_head, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x10)
		_aff(&p_current->proc, p_current->proc.instruct);
	return (0);
}

/*
** execute the register onto which there is the current processus
** see processus->pc;
*/

static void	execute_one_process(t_plst *curr, t_plst *head, char *arena, int **ref_tab)
{
	if (!curr->proc.instruct)
	{
		if (!(curr->proc.instruct = check_operation(arena, &curr->proc, ref_tab)))
		{
			curr->proc.pc = (curr->proc.pc + 1) % MEM_SIZE;
			return ;
		}
	}
	if (curr->proc.wait > 0)
		--curr->proc.wait;
	else if (curr->proc.wait == 0)
	{
		select_process_and_execute(curr, head, arena);
		free_instruction(curr->proc.instruct);
		curr->proc.instruct = NULL;
	}
	else
		curr->proc.pc = (curr->proc.pc + 1) % MEM_SIZE;
}


/*
** execute all the process, beginning with the younger.
*/

static void	execute_all_process(t_plst *head, char *arena, int **ref_tab)
{
	t_plst		*p;

	p = head;
	while (p)
	{
		execute_one_process(p, head, arena, ref_tab);
		p = p->nxt;
	}
}

/*
** execute the fight and return the winner champ's number.
*/

int				run(t_argv info)
{
	unsigned int	cycle;
	unsigned int	cycle_to_die;
	int				checks;
	t_plst			*head;
	int				ret;

	cycle_to_die = CYCLE_TO_DIE;
	checks = 0;
	head = init_process(info);
	cycle = 0;
	while (head != NULL)
	{
		if (is_there_flag(info.f, _S_) != -1 && info.f.ns != 0 && cycle % info.f.ns == 0) //
			dump(info.arena);
		else if (is_there_flag(info.f, _D_) != -1 && cycle == (uint)info.f.nd)
			dump(info.arena);
		//if (is_there_flag(info.f, _V_) != -1 && cycle % info.f.nv == 0) // NO SURE TO DO VERBOSE BONUS
		//	; // verbose, see flag.c file for more infos
		// -----------
		execute_all_process(head, info.arena, info.ref_tab);
		++cycle;
		if (cycle == cycle_to_die)
		{
			ret = process_live(&head);
			checks++;
			if (count_live(1) >= NBR_LIVE)
			{
				cycle_to_die -= CYCLE_DELTA;
				checks = 0;
			}
			if (checks >= MAX_CHECKS)
			{
				cycle_to_die -= CYCLE_DELTA;
				checks = 0;
			}
			cycle = 0;
		}
	}
	return (ret);
}
