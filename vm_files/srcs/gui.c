/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 01:07:37 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/13 23:41:27 by tfontain         ###   ########.fr       */
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

static void refresh_process(WINDOW *win, WINDOW *arena, t_process *proc)
{
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 0, 2, "CHAMPION %d'S PROCESS", proc->id);
	mvwprintw(win, 1, 13, "|  LIVE : %d", proc->exec_live);
	mvwprintw(win, 1, 1, "CARRY : %d", proc->carry);
	mvwprintw(win, 2, 1, "PC : %d", proc->pc);
	mvwprintw(win, 3, 1, "WAIT : %d", proc->wait);
	mvwprintw(win, 4, 1, "REGISTERS :");
	for (int i = 0; i < 4; i++)
		mvwprintw(win, 5 + i, 1, "%10d %10d %10d %10d", proc->reg[(i * 4)], proc->reg[(i * 4) + 1], proc->reg[(i * 4) + 2], proc->reg[(i * 4) + 3]);
	if (proc->instruct)
	{
		mvwprintw(win, 9, 1, "CURRENT OP : %s", op(proc->instruct->opcode));
		mvwprintw(win, 10, 1, "TYPES : %10s %10s %10s", types(proc->instruct->types[0]), types(proc->instruct->types[1]), types(proc->instruct->types[2]));
		mvwprintw(win, 11, 1, "ARGS :  %10d %10d %10d", proc->instruct->args[0], proc->instruct->args[1], proc->instruct->args[2]);
	}
	mvwchgat(arena, (proc->pc / 64) + 1 , ((proc->pc % 64) * 3) + 1 , 2 , A_REVERSE, proc->id, NULL);
	wrefresh(win);
	wrefresh(arena);
}

static t_wlist *build_wlist(t_plst *plst)
{
	t_plst *cur;
	t_wlist	*wlist;
	t_wlist *whead;
	int n;

	cur = plst;
	if (cur)
	{
		wlist = (t_wlist *)malloc(sizeof (t_wlist));
		whead = wlist;
		wlist->win = newwin(PROC_H, PROC_W, 0, ARENA_W + INFO_W + 1);
		wlist->next = NULL;
		cur = cur->nxt;
	}
	n = 1;
	while (cur)
	{
		wlist->next = (t_wlist *)malloc(sizeof(t_wlist));
		wlist = wlist->next;
		wlist->win = newwin(PROC_H, PROC_W, n * PROC_H, ARENA_W + INFO_W + 1);
		wlist->next = NULL;
		cur = cur->nxt;
		n++;
	}
	return (whead);
}

static int lists_same_length(t_plst *plst, t_wlist *wlist)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (plst)
	{
		n++;
		plst = plst->nxt;
	}
	while (wlist)
	{
		m++;
		wlist = wlist->next;
	}
	mvprintw(71, 40, "Plist length : %d, wlist length : %d\n", n, m);
	return (n == m);
}

static void destroy_wlist(t_wlist *wlist)
{
	t_wlist *tmp;

	while (wlist)
	{
		tmp = wlist;
		wlist = wlist->next;
		werase(tmp->win);
		wrefresh(tmp->win);
		delwin(tmp->win);
		free(tmp);
	}
}

static void refresh_wlist(t_plst *plst, t_argv *all)
{
	if (!plst)
		return ;
	t_wlist *cur;
	if (!lists_same_length(plst, all->gui->wlist_process))
	{
		destroy_wlist(all->gui->wlist_process);
		all->gui->wlist_process = build_wlist(plst);
	}
	cur = all->gui->wlist_process;
	while (cur)
	{
		refresh_process(cur->win, all->gui->win_arena, &(plst->proc));
		cur = cur->next;
		plst = plst->nxt;
	}
}

void	gui(t_argv *all, t_plst *plst)
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
	all->gui->win_champions = (WINDOW **)malloc(sizeof(WINDOW *) * all->n_champs);
	all->gui->win_arena = newwin(ARENA_H, ARENA_W, 0, 0);
	all->gui->win_vm_info = newwin(INFO_H, INFO_W, 0, 0 + ARENA_W + 1);
	all->gui->wlist_process = build_wlist(plst);
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
	refresh_arena(all->arena, all->color, all->gui->win_arena);
	refresh_info(all, all->gui->win_vm_info);
	i = 0;
	while (i < all->n_champs)
	{
		refresh_champion(&(all->champ[i]), all->gui->win_champions[i], i + 1);
		i++;
	}
	refresh_wlist(head, all);
}
