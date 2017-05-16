/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:51:00 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/10 19:51:01 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		add_argument(t_arglist *current, t_arglist **arglist)
{
	t_arglist	*tmp;

	tmp = *arglist;
	if (!tmp)
		*arglist = current;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = current;
	}
}
