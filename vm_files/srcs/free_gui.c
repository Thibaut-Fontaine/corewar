/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:45:06 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/24 19:06:06 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	free_champs(WINDOW **wins, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		delwin(wins[i]);
		i++;
	}
	free(wins);
}

static void	free_wlist(t_wlist *wlist)
{
	t_wlist *cur;
	t_wlist *tmp;

	cur = wlist;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		delwin(tmp->win);
		free(tmp);
	}
}

char		*init_color_arena(t_argv *all)
{
	int				i;
	unsigned int	j;
	char			*color;

	color = ft_strnew(MEM_SIZE);
	i = 0;
	while (i < all->n_champs)
	{
		j = 0;
		while (j < all->champ[i].prog_size)
		{
			color[j + ((MEM_SIZE / all->n_champs) * i)] = i + 1;
			j++;
		}
		i++;
	}
	return (color);
}

void		free_gui(t_argv *all)
{
	t_gui *gui;

	gui = all->gui;
	delwin(gui->win_arena);
	delwin(gui->win_vm_info);
	free_champs(gui->win_champions, all->n_champs);
	free_wlist(gui->wlist_process);
}
