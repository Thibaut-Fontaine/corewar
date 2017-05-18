/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:16:26 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:04 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		extract_instruction(t_oplist **oplist, t_parser *parser, t_asm *obj)
{
	int		i;
	char	*op;

	i = 0;
	while (parser->line[parser->current_char + i] &&
		!ft_iswhitespace(parser->line[parser->current_char + i]))
		i++;
	if (!(op = ft_strsub(parser->line, parser->current_char, i)))
	{
		ft_putendl_fd("failed to malloc operation name", 2);
		free_asm(obj);
		free_parser(parser);
		exit(-1);
	}
	add_operation(oplist, parser, op, obj);
}
