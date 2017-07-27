/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:46:49 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/27 18:59:22 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		handle_dump(t_argv *info)
{
	if (is_there_flag(info->f, _S_) != -1 && info->f.n != 0
			&& info->cycle % info->f.n == 0)
		dump(info->arena);
	else if (is_there_flag(info->f, _D_) != -1 &&
			info->cycle == (unsigned int)info->f.n)
		dump(info->arena);
}

static int		handle_live(t_argv *info, t_plst **head)
{
	if (info->cycle % info->cycle_to_die == 0 && info->cycle)
	{
		++info->checks;
		process_live(head);
		if (NBR_LIVE <= count_live(1) || info->checks % MAX_CHECKS == 0)
		{
			if ((info->cycle_to_die -= CYCLE_DELTA) <= 0)
				return (0);
			info->checks = 0;
		}
	}
	return (1);
}

int				run(t_argv *info)
{
	t_plst			*head;

	head = init_process(*info);
	if (is_there_flag(info->f, _G_) != -1)
		gui(info, head);
	while (head)
	{
		handle_dump(info);
		execute_all_process(&head, info);
		if (!handle_live(info, &head))
			break ;
		if (is_there_flag(info->f, _G_) != -1)
		{
			refresh_display(info, head);
			handle_wait();
		}
		++info->cycle;
	}
	return (*last_living_player() == 0 ? n_champ(0) : *(last_living_player()));
}
