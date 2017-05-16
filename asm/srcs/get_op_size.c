/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:44:24 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 16:44:25 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

uint32_t		get_op_size(t_oplist *op, t_parser *parser, t_param_parser p)
{
	uint32_t	size;
	t_arglist	*arglist;

	size = p.size;
	arglist = op->args;
	while (arglist)
	{
		if (arglist->type == T_REG)
			size += 1;
		else if (arglist->type == T_DIR || (arglist->type == T_DIR + T_LAB))
			size += p.label_size;
		else if (arglist->type == T_IND || (arglist->type == T_IND + T_LAB))
			size += 2;
		arglist = arglist->next;
	}
	parser->position += size;
	return (size);
}
