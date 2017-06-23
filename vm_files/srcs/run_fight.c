/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/06/23 04:55:50 by tfontain         ###   ########.fr       */
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

/*
** execute the register onto which there is the current processus
** see processus->pc;
*/

static int		execute_one_process(t_process proc, t_plst *head, char *arena, int **ref_tab)
{
	if (!proc.instruct)
		proc.instruct = check_operation(arena, &proc, ref_tab);
	if (proc.wait > 0)
		--proc.wait;
	else
		proc.pc = (proc.pc + 1) % MEM_SIZE;
	(void)head;
	return (0);
}


/*
** execute all the process, beginning with the younger.
*/

static int		execute_all_process(t_plst *p, char *arena, int **ref_tab)
{
	t_plst		*head;

	head = p;
	while (p)
	{
		execute_one_process(p->proc, head, arena, ref_tab);
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
