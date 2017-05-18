/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:34:26 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:03 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_param_format(t_arglist *arg, t_asm *obj, t_parser *parser)
{
	int		i;

	i = 0;
	if (arg->value[0] == '-')
		i++;
	while (arg->value[i])
	{
		if (!(ft_isdigit(arg->value[i])))
			format_error(arg->value, obj, parser);
		i++;
	}
}

void	check_param_error(t_oplist *op, t_asm *obj, t_parser *parser,
	t_param_parser p)
{
	t_arglist	*arglist;
	int			i;

	arglist = op->args;
	i = 0;
	check_param_number(op->args, obj, parser, p.arg_num);
	while (arglist)
	{
		if (arglist->type != T_IND + T_LAB && arglist->type != T_DIR + T_LAB)
			check_param_format(arglist, obj, parser);
		check_param_type(arglist, p.arg_types[i], obj, parser);
		i++;
		arglist = arglist->next;
	}
}
