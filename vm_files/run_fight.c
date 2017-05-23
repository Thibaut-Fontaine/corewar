/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/23 17:28:11 by mperronc         ###   ########.fr       */
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
		if (is_there_flag(info.f, _S_) && cycle % info.f.ns == 0)
			dump(info.arena);
		else if (is_there_flag(info.f, _D_) && cycle % info.f.nd == 0)
			dump_once(info.arena);
		if (is_there_flag(info.f, _V_) && cycle % info.f.nv == 0)
			; // verbose, see flag.c file for more infos
		// -----------
		execute_all_process(head, info.arena);
		++cycle;
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

int				execute_all_process(t_plst *p, const char *arena)
{
	while (p)
	{
		execute_one_process(p->proc, arena);
		p = p->nxt;
	}
	return (0);
}

/*
** execute the register onto which there is the current processus
** see processus->pc;
*/

int				execute_one_process(t_process proc, const char *arena)
{
	if (proc.wait > 0)
		--proc.wait;
	else
		(void)arena;//arena[proc.pc]; donne l'opcode
	return (0); //
}




//
// TEST FUNCS --
//
//
int				toast_func(t_argv info) // to remove
{
	//size_t	n;
	t_plst		*headd;
	t_plst		*head;
	//n = 0;
	headd = init_process(info);
	head = headd;
	//
	int reg;
	while (head)
	{
		reg = 0;
		while (reg < REG_NUMBER)
		{
			int k = 0;
			while (k < REG_SIZE)
			{
				printf("%c", (head->proc.reg[reg][k] == 0 ? '0' : 'R'));
				++k;
			}
			printf("|");
			++reg;
		}
		printf("\npc %d\n", head->proc.pc);
		printf("\ncarry %d\n", head->proc.carry);
		printf("\nwait %d\n", head->proc.wait);
		head = head->nxt;
	}
	//
	/*while (n < CYCLE_TO_DIE)
	{

		++n;
	}*/
	return (0);
}
