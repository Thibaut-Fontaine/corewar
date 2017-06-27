/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/06/27 08:23:31 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** func to check the number of call to live
*/

int		count_live(int i, int reset)
{
	static int	rem = 0;
	int			tmp;

	tmp = rem;
	if (reset != 0)
		rem = 0;
	rem += i != 0;
	return (tmp);
}

static inline int		select_process_and_execute(t_plst *p_current, t_plst *p_head, char *arena)
{
	if (p_current->proc.instruct->opcode == 0x01)
		live(p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x02)
		ld(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x03)
		st(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x04)
		add(&p_current->proc, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x05)
		sub(&p_current->proc, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x06)
		and(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x07)
		or(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x08)
		xor(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x09)
		zjmp(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0A)
		ldi(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0B)
		sti(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0C)
		frk(p_current, p_head, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x0D)
		lld(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0E)
		lldi(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0F)
		lfork(p_current, p_head, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x10)
		aff(&p_current->proc, p_current->proc.instruct);
	return (0);
}

/*
** execute the register onto which there is the current processus
** see processus->pc;
*/

static inline int		execute_one_process(t_plst *curr, t_plst *head, char *arena, int **ref_tab)
{
	if (!curr->proc.instruct)
	{
		curr->proc.instruct = check_operation(arena, &curr->proc, ref_tab);
		// proc.wait = (temps en fonction de l'opcode)
	}
	else
	{
	if (curr->proc.wait > 0)
		--curr->proc.wait;
	else if (curr->proc.wait == 0) // si le temps est null
	{
		select_process_and_execute(curr, head, arena);
		free(curr->proc.instruct); // peut etre d'autres trucs a free dans instruct
		curr->proc.instruct = NULL; // et on met bien sur instruct a NULL
	}
	else // sinon on avance de 1
		curr->proc.pc = (curr->proc.pc + 1) % MEM_SIZE;
	}
	return (0);
}


/*
** execute all the process, beginning with the younger.
*/

static inline int		execute_all_process(t_plst *head, char *arena, int **ref_tab)
{
	t_plst		*p;

	p = head;
	while (p)
	{
		execute_one_process(p, head, arena, ref_tab);
		p = p->nxt;
	}
	return (0);
}

/*
** execute the fight and return the winner champ's number.
*/

int				run(t_argv info)
{
	uintmax_t	cycle;
	int			cycle_to_die;
	int			max_checks;
	t_plst		*head;
	t_plst		*cur;

	cycle_to_die = CYCLE_TO_DIE;
	max_checks = MAX_CHECKS;
	head = init_process(info);
	cur = head;
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
		if (cycle % cycle_to_die == 0)
		{
			if (process_live(&head) == 0)
				break ;
			cycle = 0;
		}
		if (count_live(0, 1) >= NBR_LIVE)
		{
			cycle_to_die -= CYCLE_DELTA;
			max_checks = MAX_CHECKS;
		}
		if (--max_checks == 0)
		{
			--cycle_to_die;
			max_checks = MAX_CHECKS;
		}
	}
	return (0);
}
