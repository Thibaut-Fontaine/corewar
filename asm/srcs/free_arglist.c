/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arglist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:55:26 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/17 17:06:24 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_arglist(t_arglist *args)
{
	t_arglist	*tmp;
	t_arglist	*del;

	tmp = args;
	while (tmp != NULL)
	{
		if (tmp->value)
			free(tmp->value);
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}
