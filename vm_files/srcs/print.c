/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 03:54:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/30 06:02:57 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** dump the arena on the std output.
** 64 * 64
*/

void			dump(char *arena)
{
	int			sq;
	int			i;

	if (*flags() & _G_)
		return ;
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

	if (*flags() & _G_)
		return ;
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
	if (*flags() & _G_)
	{
		mvprintw(AH + 3, IW + CW + 5, "Contestant %d, \"%s\", has won !\n",
				champ_number, champ[champ_number - 1].prog_name);
		return ;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
			champ_number, champ[champ_number - 1].prog_name);
}

/*
** print a living champ as :
** Player 1, "zork", is alive.
*/

void			display_live(int ch_number, t_champion champ[MAX_PLAYERS])
{
	if (*flags() & _G_)
	{
		mvprintw(AH + 3, IW + CW + 5, "Player %d, \"%s\", is alive !\n",
		ch_number, champ[ch_number - 1].prog_name);
		return ;
	}
	ft_printf("Player %d, \"%s\", is alive !\n", ch_number,
			champ[ch_number - 1].prog_name);
}

/*
** for -v (verbose)
*/

void			display_infos(int n)
{
	if (*flags() & _G_)
		return ;
	(void)n;
}
