/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:44:42 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:25:56 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		add_operation(t_oplist **oplist, t_parser *parser, char *str,
	t_asm *obj)
{
	t_oplist	*new;
	t_oplist	*tmp;

	tmp = *oplist;
	if (!(new = malloc(sizeof(t_oplist))))
	{
		ft_putendl_fd("failed to malloc oplist", 2);
		free_asm(obj);
		free_parser(parser);
		exit(-1);
	}
	if ((new->type = get_operation_type(str, parser)) == 0)
		ft_error("Unknown instruction", parser, obj);
	new->args = extract_params(parser, obj);
	new->size = get_op_size(new, parser, parser->param_parser[new->type - 1]);
	new->next = NULL;
	check_param_error(new, obj, parser, parser->param_parser[new->type - 1]);
	if (!tmp)
		*oplist = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
