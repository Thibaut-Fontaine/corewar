/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 06:31:49 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/11 17:50:49 by mperronc         ###   ########.fr       */
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

static int	get_offset(char	*value, size_t bw, t_labellist *table)
{
	t_labellist	*label;

	if (value[0] == '%')
		value += 2;
	else
		value += 1;
	label = lookup_label(table, value);
	return (bw - label->abs_pos);
}

static void	write_arg(int fd, t_arglist *arg, size_t bytes_written, t_asm *tasm, t_oplist *op)
{
	if (arg->type == 1)
		write(fd, &(arg->value), 1);
	else if (arg->type == 2)
	{
		if (arg->value[1] == ':')
			write_number(fd, get_offset(arg->value, bytes_written, tasm->labellist), (size_t) tasm->optab[(int) op->type][LABELSIZE]);
		else
			write_number(fd, ft_atoi(&(arg->value[1])), 2);
	}
	else
	{
		if (arg->value[0] == ':')
			write_number(fd, get_offset(arg->value, bytes_written, tasm->labellist), 2);
		else
			write_number(fd, ft_atoi(&(arg->value[1])), 2);
	}
}

void	write_args(int fd, t_oplist *op, size_t bytes_written, t_asm *tasm)
{
	t_arglist	*arg;

	arg = op->args;
	while (arg != NULL)
	{
		write_arg(fd, arg, bytes_written, tasm, op);
		arg = arg->next;
	}
}
