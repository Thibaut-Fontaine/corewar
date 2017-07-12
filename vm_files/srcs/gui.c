/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 01:07:37 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/12 23:48:17 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static char *types(int type)
{
	if (type == 1)
		return ("REGISTER");
	else if (type == 2)
		return ("DIRECT");
	else if (type == 4)
		return "INDIRECT";
	else
		return ("");
}

static char *op(int opcode)
{
	static char ops[16][6]  = {"LIVE","LD","ST","ADD","SUB","AND","OR","XOR",
							"ZJMP","LDI","STI","FORK","LLD","LLDI","LFORK","AFF"};

	return ops[opcode - 1];
}

static void refresh_arena(char *arena, char *color, WINDOW *win)
{
	int	i;
	int x;
	int y;

	box(win, 0, 0);
	mvwprintw(win, 0, 2, "ARENA");
	i = 0;
	x = 1;
	y = 1;
	while (i < MEM_SIZE)
	{
		wattron(win, COLOR_PAIR(color[i]));
		mvwprintw(win, y , x, ft_bytohex(arena[i], TRUE));
		x += 2;
		if (x >= ARENA_W - 2)
		{
			x = 1;
			y++;
		}
		if (x != 1)
		{
			mvwprintw(win, y, x, " ");
			x += 1;
			if (x >= ARENA_W - 2)
			{
				x = 1;
				y++;
			}
		}
		wattroff(win, COLOR_PAIR(color[i]));
		i++;
	}
	wrefresh(win);
}

static void refresh_info(t_argv *all, WINDOW *win)
{
	box(win, 0, 0);
	mvwprintw(win, 0, 2, "VM STATUS");
	mvwprintw(win, 1, 1, "CYCLE : %d", all->cycle);
	mvwprintw(win, 2, 1, "CYCLE TO DIE : %d", all->cycle_to_die);
	mvwprintw(win, 3, 1, "CHECKS : %d", all->checks);
	mvwprintw(win, 4, 1, "LAST LIVING PLAYER : %d", *last_living_player());
	wrefresh(win);
}

static void refresh_champion(t_header *champ, WINDOW *win, int i)
{
	box(win, 0, 0);
	mvwprintw(win, 0, 2, "CHAMPION %d", i);
	mvwprintw(win, 1, 1, champ->prog_name);
	mvwprintw(win, 2, 1, champ->comment);
	wrefresh(win);
}

static void refresh_process(t_process *proc, WINDOW *arena)
{
	werase(proc->win);
	box(proc->win, 0, 0);
	mvwprintw(proc->win, 0, 2, "PROCESS %d", proc->id);
	mvwprintw(proc->win, 1, 13, "|  LIVE : %d", proc->exec_live);
	mvwprintw(proc->win, 1, 1, "CARRY : %d", proc->carry);
	mvwprintw(proc->win, 2, 1, "PC : %d", proc->pc);
	mvwprintw(proc->win, 3, 1, "WAIT : %d", proc->wait);
	mvwprintw(proc->win, 4, 1, "REGISTERS :");
	for (int i = 0; i < 4; i++)
		mvwprintw(proc->win, 5 + i, 1, "%10d %10d %10d %10d", proc->reg[(i * 4)], proc->reg[(i * 4) + 1], proc->reg[(i * 4) + 2], proc->reg[(i * 4) + 3]);
	if (proc->instruct)
	{
		mvwprintw(proc->win, 9, 1, "CURRENT OP : %s", op(proc->instruct->opcode));
		mvwprintw(proc->win, 10, 1, "TYPES : %10s %10s %10s", types(proc->instruct->types[0]), types(proc->instruct->types[1]), types(proc->instruct->types[2]));
		mvwprintw(proc->win, 11, 1, "ARGS :  %10d %10d %10d", proc->instruct->args[0], proc->instruct->args[1], proc->instruct->args[2]);
	}
	mvwchgat(arena, (proc->pc / 64) + 1 , ((proc->pc % 64) * 3) + 1 , 2 , A_REVERSE, 0, NULL);
	wrefresh(proc->win);
	wrefresh(arena);
}

static void init_color_arena(t_argv *all)
{
	int i;
	unsigned int j;

	i = 0;
	while (i < all->n_champs)
	{
		mvprintw(71 + i, 40, "%d", all->champ[i].prog_size);
		j = 0;
		while (j < all->champ[i].prog_size)
		{
			all->gui->color[j + ((MEM_SIZE / all->n_champs) * i)] = i + 1;
			j++;
		}
		i++;
	}
}

void	gui(t_argv *all)
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

	all->gui = (t_gui *)malloc(sizeof(t_gui));
	all->gui->color = ft_strnew(MEM_SIZE);
	init_color_arena(all);
	all->gui->win_champions = (WINDOW **)malloc(sizeof(WINDOW *) * all->n_champs);
	all->gui->win_arena = newwin(ARENA_H, ARENA_W, 0, 0);
	all->gui->win_vm_info = newwin(INFO_H, INFO_W, 0, 0 + ARENA_W + 1);
	int i = 0;
	while (i < all->n_champs)
	{
		all->gui->win_champions[i] = newwin(CHAMP_H, CHAMP_W,
			INFO_H + (i * CHAMP_H), ARENA_W + 1);
		i++;
	}
}

void	refresh_display(t_argv *all, t_plst *head)
{
	int i;

	mvprintw(70, 30, "Press 1, 2, 3 or 4 to go forward 1, 10, 100 or 1000 cycles");
	refresh_arena(all->arena, all->gui->color, all->gui->win_arena);
	refresh_info(all, all->gui->win_vm_info);
	i = 0;
	while (i < all->n_champs)
	{
		refresh_champion(&(all->champ[i]), all->gui->win_champions[i], i + 1);
		i++;
	}
	while (head)
	{
		refresh_process(&(head->proc), all->gui->win_arena);
		head = head->nxt;
	}
}
