/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 06:11:08 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/15 10:59:43 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

void		fill_process_init(t_plst *cur, int n_champs, int i)
{
	size_t	reg;

	reg = 0;
	while (reg < REG_NUMBER)
		ft_bzero(cur->proc.reg[reg++], REG_SIZE);
	cur->proc.pc = (MEM_SIZE / n_champs) * (n_champs - i - 1);
	cur->proc.carry = 0;
	cur->proc.wait = 0;
	cur->nxt = NULL;
}

/*
** init a list with the starting processus, beginning with the last and
** finishing with the first.
*/

t_plst		*init_process(t_argv info)
{
	t_plst	*head;
	t_plst	*cur;
	int		i;

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
** add a forked process to the start of the list (he become the head)
** because the last process is the first to be executed.
*/

add_process()
{
}
