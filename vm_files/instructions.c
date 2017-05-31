/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 05:15:44 by tfontain         ###   ########.fr       */
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

int					ld()
{
	return (0);
}

int					st()
{
	return (0);
}

int					add()
{
	return (0);
}

int					sub()
{
	return (0);
}

int					and()
{
	return (0);
}

int					or()
{
	return (0);
}

int					xor()
{
	return (0);
}

int					zjmp()
{
	return (0);
}

int					ldi()
{
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
