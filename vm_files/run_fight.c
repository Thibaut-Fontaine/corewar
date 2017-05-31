/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 03:09:12 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** func to check the number of call to live
*/

int				count_live(int i, int reset)
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
	while (head != NULL) // tant que il existe des process
	{
		// affichages :
		if (is_there_flag(info.f, _S_) != -1 && info.f.ns != 0 && cycle % info.f.ns == 0) //
			dump(info.arena);
		else if (is_there_flag(info.f, _D_) != -1 && cycle == (uint)info.f.nd)
			dump(info.arena);
		//if (is_there_flag(info.f, _V_) != -1 && cycle % info.f.nv == 0) // NO SURE TO DO VERBOSE BONUS
		//	; // verbose, see flag.c file for more infos
		// -----------
		execute_all_process(head, info.arena); // on execute tous les process un par un
		++cycle; // on incremente car le reste doit s'executer apres au moins 1 cycle
		if (cycle % cycle_to_die == 0) // si on est arrive a CYCLE_TO_DIE
			if (process_live(&head) == 0) // alors on check tous les process dont live vaut 0 et on les tue
				break ;
		if (count_live(0, 1) >= NBR_LIVE) // si il y a eu au moins NBR_LIVE exécutions de live
			cycle_to_die -= CYCLE_DELTA; // on décrés
		if (--max_checks == 0) // Si on n’a pas décrémenté CYCLE_TO_DIE depuis MAX_CHECKS vérifications
		{
			--cycle_to_die; // on le decremente
			max_checks = MAX_CHECKS;
		}
	}
	return (0);
}

/*
** execute all the process, beginning with the younger.
*/

int				execute_all_process(t_plst *p, char *arena)
{
	t_plst		*head;

	head = p;
	while (p)
	{
		execute_one_process(p->proc, head, arena);
		p = p->nxt;
	}
	return (0);
}

/*
** execute the register onto which there is the current processus
** see processus->pc;
*/

int				execute_one_process(t_process proc, t_plst *head, char *arena)
{
	if (!proc.instruct)
		proc.instruct = check_operation(arena + proc.pc);
	else if (proc.wait > 0)
		--proc.wait;
	else
		proc.pc++; //to remove
		exec_instruction(arena, proc, head); // et effacer instruct ?
	return (0); 
}

