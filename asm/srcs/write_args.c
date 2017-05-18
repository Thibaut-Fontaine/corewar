/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 06:31:49 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/16 22:26:16 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_labellist	*lookup_label(t_labellist *start, char *label)
{
	t_labellist	*iter;

	iter = start;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->name, label) == 0)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

static int			get_offset(char *value, size_t bw, t_labellist *table)
{
	t_labellist	*label;

	label = lookup_label(table, value);
	return (label->abs_pos - bw);
}

static size_t		get_labelsize(t_asm *tasm, t_oplist *op)
{
	size_t ret;

	ret = (size_t)ft_atoi(tasm->optab[(int)op->type][LABELSIZE]);
	return (ret);
}

void				write_args(int fd, t_oplist *op,
								size_t bytes_written, t_asm *tasm)
{
	t_arglist	*arg;

	arg = op->args;
	while (arg != NULL)
	{
		if (arg->type == T_REG)
			write_number(fd, ft_atoi(arg->value), 1);
		else if (arg->type == T_DIR)
			write_number(fd, ft_atoi(arg->value), get_labelsize(tasm, op));
		else if (arg->type == (T_DIR | T_LAB))
			write_number(fd,
				get_offset(arg->value, bytes_written, tasm->labellist),
				get_labelsize(tasm, op));
		else if (arg->type == T_IND)
			write_number(fd, ft_atoi(arg->value), 2);
		else if (arg->type == (T_IND | T_LAB))
			write_number(fd,
				get_offset(arg->value, bytes_written, tasm->labellist), 2);
		arg = arg->next;
	}
}
