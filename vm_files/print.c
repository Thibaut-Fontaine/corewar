/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 03:54:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/23 17:04:10 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** dump the arena on the std output.
** 64 * 64
*/

static float	ft_sqrt(float num)
{
	float		guess;
	float		e;
	float		upperbound;

	guess = 1;
	e = 0.001;
	upperbound = num / guess;
	guess = (upperbound + guess) / 2;
	while (!(guess * guess >= num - e && guess * guess <= num + e))
	{
		upperbound = num / guess;
		guess = (upperbound + guess) / 2;
	}
	return (guess);
}

void			dump(char *arena)
{
	int			sq;
	int			i;

	sq = ft_sqrt(MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % sq == 0)
			ft_printf("0x%04x : ", i);
		ft_putstr(ft_bytohex(arena[i], TRUE));
		ft_putchar((i + 1) % sq == 0 ? '\n' : ' ');
		++i;
	}
}

/*
** print champions as following :
** * Player 1, weighing 23 bytes, "zork" ("just a basic living prog") !
** * Player 2, weighing 36 bytes, "prout" ("best champ ever.") !
** etc.
*/

void			introducing_contestants(int n_champs,
		t_header champ[MAX_PLAYERS])
{
	int			i;

	ft_putstr("Introducing contestants...\n");
	i = 0;
	while (i < n_champs)
	{
		ft_putstr("* Player ");
		ft_putnbr(i + 1);
		ft_putstr(", weighing ");
		ft_putnbr(champ[i].prog_size);
		ft_putstr(" bytes, \"");
		ft_putstr(champ[i].prog_name);
		ft_putstr("\" (\"");
		ft_putstr(champ[i].comment);
		ft_putstr("\") !\n");
		++i;
	}
}

/*
** print the winner champion as following :
** Contestant 2, "Celebration Funebre v0.99pl42", has won !
*/

void			display_winner(int champ_number, t_header champ[MAX_PLAYERS])
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
			champ_number, champ[champ_number - 1].prog_name);
}

/*
** for -v (verbose)
*/

void			diplay_infos(int n)
{
	(void)n;
}
