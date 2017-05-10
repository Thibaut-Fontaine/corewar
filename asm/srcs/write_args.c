/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 06:31:49 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/10 06:52:54 by mperronc         ###   ########.fr       */
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

static void	write_arg(int fd, t_arglist *arg, size_t bytes_written, t_asm *tasm)
{
	if (arg->type == 1)
		write(fd, &(arg->value), 1);
	else if (arg->type == 2)
	{
		if (arg->value[1] == ':')
			write_number32(fd, get_offset(arg->value, bytes_written, tasm->labellist));
		else
			write_number32(fd, ft_atoi(&(arg->value[1])));
	}
}

void	write_args(int fd, t_arglist *args, size_t bytes_written, t_asm *tasm)
{
	t_arglist	*arg;

	arg = args;
	while (arg != NULL)
	{
		write_arg(fd, arg, bytes_written, tasm);
		arg = arg->next;
	}
}
