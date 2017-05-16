/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:34:26 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 15:34:27 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_param_format(t_arglist *arg, t_parser *parser)
{
	int		i;

	i = 0;
	while (arg->value[i])
	{
		if (!(ft_isdigit(arg->value[i])))
			format_error(arg->value, parser);
		i++;
	}
}

void	check_param_error(t_oplist *op, t_parser *parser, t_param_parser p)
{
	t_arglist	*arglist;

	arglist = op->args;
	check_param_number(op->args, parser, p.arg_num);
	while (arglist)
	{
		if (arglist->type != T_IND + T_LAB && arglist->type != T_DIR + T_LAB)
			check_param_format(arglist, parser);
		arglist = arglist->next;
	}
}
