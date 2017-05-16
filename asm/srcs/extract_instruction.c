/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:16:26 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/27 11:16:28 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		extract_instruction(t_oplist **oplist, t_parser *parser)
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
		exit(-1);
	}
	add_operation(oplist, parser, op);
}
