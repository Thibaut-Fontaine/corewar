/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/15 16:05:59 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** execute the fight and return the winner champ's number.
*/

int				run(t_argv info)
{
	size_t		n;
	t_plst		*head;
	t_plst		*cur;

	head = init_process(info);
	cur = head;
	n = 0;
	while (n < CYCLE_TO_DIE)
	{
		
		++n;
	}
	return (0);
}

/*
** execute the register onto which there is the current processus
** see processus->pc;
*/

int				execute_process(t_process proc, const char *arena)
{
	if (proc.wait > 0)
	{
		--proc.wait;
		proc.pc = (proc.pc + 1) % MEM_SIZE; // modulo pour l'arena
	}
	else
		;//arena[proc.pc]; donne l'opcode
	return (0); //
}

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
