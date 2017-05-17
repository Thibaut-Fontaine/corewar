/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_oplist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:55:26 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/17 17:02:15 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_oplist(t_oplist *ops)
{
	t_oplist	*tmp;
	t_oplist	*del;

	tmp = ops;
	while (tmp != NULL)
	{
		if (tmp->args)
			free_arglist(tmp->args);
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}
