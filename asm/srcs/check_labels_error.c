/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 18:18:20 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/15 13:23:17 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		label_exist(char *str, t_labellist *labellist)
{
	t_labellist	*list;

	list = labellist;
	while (list)
	{
		if (ft_strcmp(str, list->name) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void			check_labels_error(t_labellist *labellist, t_oplist *oplist,
	t_asm *obj, t_parser *parser)
{
	t_oplist	*current;
	t_arglist	*arg;

	current = oplist;
	arg = oplist->args;
	while (current)
	{
		arg = current->args;
		while (arg)
		{
			if (arg->type == T_LAB + T_DIR || arg->type == T_LAB + T_IND)
				if (!labellist || label_exist(arg->value, labellist) == 0)
					label_error(arg->value, arg->line, obj, parser);
			arg = arg->next;
		}
		current = current->next;
	}
}
