/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/13 01:14:51 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** func to check the number of call to live
*/

static int		select_process_and_execute(t_plst *p_current, t_plst *p_head, char *arena, char *color)
{
	// ft_printf("instruction n.%d executee.\n", p_current->proc.instruct->opcode); //
	if (check_register(p_current->proc.instruct) == 0)
		return (0);
	if (p_current->proc.instruct->opcode == 0x01)
		_live(&p_current->proc, p_current->proc.instruct);
	if (p_current->proc.instruct->opcode == 0x02)
		_ld(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x03)
		_st(&p_current->proc, p_current->proc.instruct, arena, color);
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
		_zjmp(&p_current->proc, arena);
	if (p_current->proc.instruct->opcode == 0x0A)
		_ldi(&p_current->proc, p_current->proc.instruct, arena);
	if (p_current->proc.instruct->opcode == 0x0B)
		_sti(&p_current->proc, p_current->proc.instruct, arena, color);
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

static void		execute_one_process(t_plst *curr, t_plst *head, char *arena, char *color,
		int **ref_tab)
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
		select_process_and_execute(curr, head, arena, color);
		free_instruction(curr->proc.instruct);
		if ((curr->proc.instruct = check_operation(arena, &curr->proc, ref_tab)))
			--curr->proc.wait;
	}
	else
		curr->proc.pc = (curr->proc.pc + 1) % MEM_SIZE;
}
/*
** execute all the process, beginning with the younger.
*/

void			execute_all_process(t_plst *head, char *arena, char *color, int **ref_tab)
{
	t_plst		*p;

	p = head;
	while (p)
	{
		execute_one_process(p, head, arena, color, ref_tab);
		p = p->nxt;
	}
}

/*
** execute the fight and return the winner champ's number.
*/

int					run(t_argv *info)
{
	t_plst			*head;
	int				ch;
	int				wait;

	wait = 0;
	head = init_process(*info);
	info->cycle = 0;
	info->checks = 0;
	info->cycle_to_die = CYCLE_TO_DIE;
	while (head)
	{
		if (is_there_flag(info->f, _S_) != -1 && info->f.ns != 0
				&& info->cycle % info->f.ns == 0)
			dump(info->arena);
		else if (is_there_flag(info->f, _D_) != -1 && info->cycle == (uint)info->f.nd)
			dump(info->arena);
		execute_all_process(head, info->arena, info->color, info->ref_tab);
		if (info->cycle % info->cycle_to_die == 0 && info->cycle)
		{
			++info->checks;
			process_live(&head);
			if (NBR_LIVE <= count_live(1) || info->checks % MAX_CHECKS == 0)
			{
				info->cycle_to_die -= CYCLE_DELTA;
				info->checks = 0;
			}
		}
		if (is_there_flag(info->f, _N_) != -1)
		{
			refresh_display(info, head);
			if (wait == 0)
			{
				ch = getch();
				if (ch == '1')
					wait++;
				else if (ch == '2')
					wait += 10;
				else if (ch == '3')
					wait += 100;
				else if (ch == '4')
					wait += 1000;
			}
			wait ? wait-- : wait;
		}
		++info->cycle;
	}
	return (*last_living_player() == 0 ? n_champ(0) : *(last_living_player()));
}
