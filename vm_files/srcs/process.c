/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 06:11:08 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/13 23:56:42 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void 	fill_process_init(t_plst *cur, int n_champs, int i)
{
	i = n_champs - i - 1; // verifier que les champions sont bien inseres dans la liste en ordre inverse
	cur->proc.instruct = NULL;
	ft_bzero(cur->proc.reg, sizeof(cur->proc.reg));
	//cur->proc.pc = (MEM_SIZE / n_champs) * (n_champs - i - 1);
	cur->proc.pc = (MEM_SIZE / n_champs) * i;
	cur->proc.carry = 0;
	cur->proc.wait = 0;
	cur->proc.instruct = NULL;
	cur->proc.id = i + 1;
	cur->proc.reg[0] = 0xFFFFFFFF - i;
	cur->proc.exec_live = 0;
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

int				process_live(t_plst **head) // fonction a refaire
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
	if (p->nxt == NULL && p->proc.exec_live == 1)
		p->proc.exec_live = 0;
	while (p && p->nxt)
	{
		if (p->nxt->proc.exec_live == 0)
		{
			tmp = p->nxt->nxt;
			if (p->nxt->proc.instruct)
				free(p->nxt->proc.instruct);
			free(p->nxt);
			p->nxt = tmp;
		}
		else
			p->nxt->proc.exec_live = 0;
		if (p->nxt != NULL)
			p->nxt = p->nxt->nxt;
	}
	return (0);
}
