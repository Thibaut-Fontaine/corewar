/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 01:26:41 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 02:00:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** this file contains instructions to execute only.
*/

int					live(t_process proc, int direct)
{
	count_live(1, 0); // increment. du nbr de live
	display_live(proc, direct, ); // on affiche le joueur vivant
}

int					ld()
{
}

int					st()
{
}

int					add()
{
}

int					sub()
{
}

int					and()
{
}

int					or()
{
}

int					xor()
{
}

int					zjmp()
{
}

int					ldi()
{
}

int					sti()
{
}

int					fork()
{
}

int					lld()
{
}

int					lldi()
{
}

int					lfork()
{
}

int					aff()
{
}
