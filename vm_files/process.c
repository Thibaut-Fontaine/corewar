/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 06:11:08 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 02:03:42 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

void			fill_process_init(t_plst *cur, int n_champs, int i)
{
	size_t		reg;

	reg = 0;
	while (reg < REG_NUMBER)
		ft_bzero(cur->proc.reg[reg++], REG_SIZE);
	cur->proc.pc = (MEM_SIZE / n_champs) * (n_champs - i - 1);
	cur->proc.carry = 0;
	cur->proc.wait = 0;
	cur->proc.live = 0;
	cur->proc.instruct = NULL;
	cur->proc.id = i + 1; // numero du joueur
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
	size_t		reg;
	t_plst		*new;

	if ((new = malloc(sizeof(t_plst))) == NULL)
		error(_ERR_STD)(NULL);
	reg = 0;
	while (reg < REG_NUMBER)
	{
		ft_memmove(new->proc.reg[reg], to_fork->proc.reg[reg], REG_SIZE);
		++reg;
	}
	new->proc.pc = pc;
	new->proc.carry = to_fork->proc.carry;
	new->proc.wait = 0;
	new->proc.live = 0;
	new->proc.instruct = NULL;
	new->proc.id = to_fork->proc.id;
	new->nxt = *head;
	*head = new;
}

/*
** kill all process with a live egal to 0
** and replace all live != 0 of process with 0
** return 1 if there is a least 1 process still alive
** return 0 if all process are mothafuckin'DEAD
*/

 // il manque le free du proc->instruct si il n'est pas NULL

int				process_live(t_plst **head)
{
	t_plst	*cur;
	t_plst	*tmp;

	if (head == NULL)
		return (0);
	if ((*head)->proc.live)
		(*head)->proc.live = 0;
	else
	{
		tmp = (*head)->nxt;
		free(*head);
		*head = tmp;
	}
	cur = *head;
	while (cur && cur->nxt) // pas sur
	{
		if (cur->nxt->proc.live)
			cur->nxt->proc.live = 0;
		else
		{
			tmp = cur->nxt->nxt;
			free(cur->nxt);
			cur->nxt = tmp;
		}
		cur = cur->nxt;
	}
	return (*head != NULL);
}
