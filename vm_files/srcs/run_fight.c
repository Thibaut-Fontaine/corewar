/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/27 11:33:01 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				run(t_argv *info)
{
	t_plst			*head;
	int				ch;
	int				wait;

	wait = 0;
	head = init_process(*info);
	info->cycle = 0;
	info->checks = 0;
	info->cycle_to_die = CYCLE_TO_DIE;
	if (is_there_flag(info->f, _G_) != -1)
		gui(info, head);
	while (head)
	{
		if (is_there_flag(info->f, _S_) != -1 && info->f.n != 0
				&& info->cycle % info->f.n == 0)
			dump(info->arena);
		else if (is_there_flag(info->f, _D_) != -1 &&
				info->cycle == (unsigned int)info->f.n)
			dump(info->arena);
		execute_all_process(&head, info);
		if (info->cycle % info->cycle_to_die == 0 && info->cycle)
		{
			++info->checks;
			process_live(&head);
			if (NBR_LIVE <= count_live(1) || info->checks % MAX_CHECKS == 0)
			{
				if ((info->cycle_to_die -= CYCLE_DELTA) <= 0)
					break ;
				info->checks = 0;
			}
		}
		if (is_there_flag(info->f, _G_) != -1)
		{
			refresh_display(info, head);
			if (wait == 0)
			{
				ch = getch();
				if (ch == '1')
					wait++;
				else if (ch == '2')
					wait += 10;
				else if (ch == '3')
					wait += 100;
				else if (ch == '4')
					wait += 1000;
			}
			wait ? wait-- : wait;
		}
		++info->cycle;
	}
	return (*last_living_player() == 0 ? n_champ(0) : *(last_living_player()));
}
