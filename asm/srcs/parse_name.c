/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:48:00 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/04 18:48:02 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/asm.h"

void		parse_name(t_asm *obj, t_parser *parser)
{
	size_t		j;

	while (ft_iswhitespace(parser->line[parser->current_char]))
		parser->current_char++;
	if (parser->line[parser->current_char] != '"')
		ft_error("Expected double quotes around name", parser);
	parser->current_char++;
	j = 0;
	while (parser->line[parser->current_char] && parser->line[parser->current_char] != '"')
	{
		if (j >= PROG_NAME_LENGTH)
		{
			ft_putendl_fd("Name to long", 2);
			exit(-1);
		}
		obj->header.prog_name[j] = parser->line[parser->current_char];
		j++;
		parser->current_char++;
	}
	if (parser->line[parser->current_char] != '"')
		ft_error("Expected double quotes around name", parser);
}