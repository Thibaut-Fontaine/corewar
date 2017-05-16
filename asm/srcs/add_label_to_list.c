/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:00:53 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/09 16:00:56 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	add_label_to_list(t_labellist **labellist, t_parser *parser, char *name)
{
	t_labellist	*new;

	if (!(new = malloc(sizeof(t_labellist))))
	{
		ft_putendl_fd("failed to malloc labellist", 2);
		exit(-1);
	}
	new->name = name;
	new->abs_pos = parser->position;
	new->next = *labellist;
	*labellist = new;
}
