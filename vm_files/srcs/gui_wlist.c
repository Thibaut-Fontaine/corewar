/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_wlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:01:53 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/18 20:06:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define Y ((n % WPH) * PH)
#define X (AW + ((n / WPH) * PW))

t_wlist			*build_wlist(t_plst *plst)
{
	t_plst	*cur;
	t_wlist	*wlist;
	t_wlist *whead;
	int		n;

	cur = plst;
	if (cur)
	{
		wlist = (t_wlist *)malloc(sizeof(t_wlist));
		whead = wlist;
		wlist->win = newwin(PH, PW, 0, AW);
		wlist->next = NULL;
		cur = cur->nxt;
	}
	n = 1;
	while (cur)
	{
		wlist->next = (t_wlist *)malloc(sizeof(t_wlist));
		wlist = wlist->next;
		wlist->win = newwin(PH, PW, Y, X);
		wlist->next = NULL;
		cur = cur->nxt;
		n++;
	}
	return (whead);
}

static int		lists_same_length(t_plst *plst, t_wlist *wlist)
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
	return (n == m);
}

static void		destroy_wlist(t_wlist *wlist)
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

void			refresh_wlist(t_plst *plst, t_argv *all)
{
	t_wlist *cur;

	if (!plst)
		return ;
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
