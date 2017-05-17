/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_labellist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:55:26 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/17 17:06:39 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_labellist(t_labellist *labels)
{
	t_labellist	*tmp;
	t_labellist	*del;

	tmp = labels;
	while (tmp != NULL)
	{
		if (tmp->name)
			free(tmp->name);
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}
