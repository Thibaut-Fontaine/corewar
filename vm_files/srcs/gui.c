/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 01:07:37 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/18 20:04:27 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char			*types(int type)
{
	if (type == 1)
		return ("REGISTER");
	else if (type == 2)
		return ("DIRECT");
	else if (type == 4)
		return ("INDIRECT");
	else
		return ("");
}

char			*op(int opcode)
{
	static char ops[16][6] = {"LIVE", "LD", "ST", "ADD", "SUB", "AND", "OR",
	"XOR", "ZJMP", "LDI", "STI", "FORK", "LLD", "LLDI", "LFORK", "AFF"};

	return (ops[opcode - 1]);
}

void			write_color(char *color, int index, char id)
{
	color[mod(index + 0, MEM_SIZE)] = id;
	color[mod(index + 1, MEM_SIZE)] = id;
	color[mod(index + 2, MEM_SIZE)] = id;
	color[mod(index + 3, MEM_SIZE)] = id;
}

static void		init_gui(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	clear();
	refresh();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, P1_COLOR, COLOR_BLACK);
	init_pair(2, P2_COLOR, COLOR_BLACK);
	init_pair(3, P3_COLOR, COLOR_BLACK);
	init_pair(4, P4_COLOR, COLOR_BLACK);
}

void			gui(t_argv *all, t_plst *plst)
{
	int i;

	init_gui();
	all->gui = (t_gui *)malloc(sizeof(t_gui));
	all->gui->win_champions =
	(WINDOW **)malloc(sizeof(WINDOW *) * all->n_champs);
	all->gui->win_arena = newwin(AH, AW, 0, 0);
	all->gui->win_vm_info = newwin(IH, IW, AH, 0);
	all->gui->wlist_process = build_wlist(plst);
	i = 0;
	while (i < all->n_champs)
	{
		all->gui->win_champions[i] = newwin(CH, CW, AH + (CH * i), IW);
		i++;
	}
}
