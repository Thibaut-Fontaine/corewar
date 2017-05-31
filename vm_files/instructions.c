/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 10:46:58 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** this file contains instructions to execute only.
*/

int					live(int direct)
{
	count_live(1, 0); // increment. du nbr de live
	get_champion()[direct].live = 1; // on met le live du champion a 1
	display_live(direct, get_champion()); // on affiche le joueur vivant
	return (0);
}

int					ld(t_process proc, int direct, int *dest)
{
	if ((*dest = direct) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					st(t_process proc, int direct, int *dest)
{
	if ((*dest = direct) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					add(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 + source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					sub(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 - source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					and(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 & source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					or(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 | source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					xor(t_process proc, int source1, int source2, int *dest)
{
	if ((*dest = source1 ^ source2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					zjmp(t_process proc, int source)
{
	if (proc.carry == 1)
		proc.pc = (proc.pc + source) % MEM_SIZE;
	return (0);
}

int					ldi(t_process proc, int indirect1, int indirect2, int *dest)
{
	if ((*dest = indirect1 + indirect2) == 0)
		proc.carry = 1;
	else
		proc.carry = 0;
	return (0);
}

int					sti()
{
	return (0);
}

int					fork()
{
	return (0);
}

int					lld()
{
	return (0);
}

int					lldi()
{
	return (0);
}

int					lfork()
{
	return (0);
}

int					aff()
{
	return (0);
}
