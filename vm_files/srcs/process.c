/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 06:11:08 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/12 00:45:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void 	fill_process_init(t_plst *cur, int n_champs, int i)
{
	cur->proc.instruct = NULL;
	ft_bzero(cur->proc.reg, sizeof(cur->proc.reg));
	cur->proc.pc = (MEM_SIZE / n_champs) * (n_champs - i - 1);
	cur->proc.carry = 0;
	cur->proc.wait = 0;
	cur->proc.instruct = NULL;
	cur->proc.id = i + 1;
	cur->proc.reg[0] = 0xFFFFFFFF - i;
	cur->proc.exec_live = 0;
	cur->proc.win = newwin(PROC_H, PROC_W, PROC_H * (cur->proc.id - 1), ARENA_W + INFO_W + 1);
	cur->nxt = NULL;
}

/*
** init a list with the starting processus, beginning with the last and
** finishing with the first.
*/

t_plst			*init_process(t_argv info)
{
	t_plst		*head;
	t_plst		*cur;
	int			i;

	head = NULL;
	i = 0;
	while (i < info.n_champs)
	{
		if (head == NULL)
		{
			if ((cur = malloc(sizeof(t_plst))) == NULL)
				error(_ERR_STD)(NULL);
			head = cur;
		}
		fill_process_init(cur, info.n_champs, i);
		if (i + 1 == info.n_champs)
			break ;
		if ((cur->nxt = malloc(sizeof(t_plst))) == NULL)
			error(_ERR_STD)(NULL);
		cur = cur->nxt;
		++i;
	}
	return (head);
}

/*
** add a forked process to the start of the list by copy (he become the head)
** because the last process is the first to be executed.
*/

void			fork_process(t_plst **head, t_plst *to_fork, int pc)
{
	t_plst		*new;

	if ((new = malloc(sizeof(t_plst))) == NULL)
		error(_ERR_STD)(NULL);
	ft_memcpy(new->proc.reg, to_fork->proc.reg, sizeof(to_fork->proc.reg));
	new->proc.pc = pc;
	new->proc.carry = to_fork->proc.carry;
	new->proc.wait = 0;
	new->proc.instruct = NULL;
	new->proc.id = to_fork->proc.id;
	new->proc.exec_live = 0;
	new->nxt = *head;
	*head = new;
}

int				process_live(t_plst **head)
{
	t_plst		*p;
	t_plst		*tmp;

	while (*head && (*head)->proc.exec_live == 0)
	{
		tmp = (*head)->nxt;
		if ((*head)->proc.instruct)
			free((*head)->proc.instruct);
		free((*head));
		*head = tmp;
	}
	p = *head;
	while (p)
	{
		if (p->proc.exec_live == 0)
		{
			tmp = p->nxt;
			if (p->proc.instruct)
				free(p->proc.instruct);
			free(p);
			p = tmp;
		}
		else
			p->proc.exec_live = 0;
		p = p->nxt;
	}
	return (0);
}


//OLD:
/*
** kill all process with a champ's live egal to 0
** and replace all live != 0 of process with 0
** return 0 if there is a least 1 process still alive
** return the id of the last living champ if all process are dead


int				process_live(t_plst **head)
{
	int			i;
	t_plst		*cur;
	t_plst		*tmp;
	int			ret;

	i = 0;
	ret = 0;
	while (i < MAX_PLAYERS)
	{
		if (get_champion()[i].live)
			get_champion()[i].live = 0;
		else
		{
			while (*head && (*head)->proc.id == i + 1)
			{
				tmp = (*head)->nxt;
				if ((*head)->nxt == NULL)
					ret = (*head)->proc.id;
				free(*head);
				*head = tmp;
			}
			cur = *head;
			while (cur && cur->nxt)
			{
				if (cur->nxt->proc.id == i + 1)
				{
					tmp = cur->nxt->nxt;
					free(cur->nxt);
					cur->nxt = tmp;
				}
				cur = cur->nxt;
			}
		}
		++i;
	}
	return (ret);
}*/
