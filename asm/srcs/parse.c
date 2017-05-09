/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:50:57 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/13 15:50:59 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			parse_line(t_asm *obj, t_parser *parser)
{
	parser->line = ft_strtrim(parser->line);
	if (ft_strlen(parser->line) == 0 || parser->line[0] == COMMENT_CHAR)
		return ;
	if (!parser->check_name || !parser->check_comment)
		if (parse_header(obj, parser))
			return ;
	remove_com(&parser->line);
	extract_labeldecl(&obj->labellist, parser);
	while (ft_iswhitespace(parser->line[parser->current_char]))
		parser->current_char++;
	if (!parser->line[parser->current_char])
		return ;
	extract_instruction(&obj->oplist, parser);
}

t_asm			parse(char *av)
{
	t_parser	parser;
	t_asm		obj;

	parser.current_line = 1;
	parser.position = 0;
	parser.check_name = 0;
	parser.check_comment = 0;
	asm_init(&obj);
	if ((parser.fd = open(av, O_RDONLY)) == -1)
		ft_putendl_fd("failed to open file", 2);
	while (get_next_line(parser.fd, &parser.line))
	{
		parser.current_char = 0;
		parse_line(&obj, &parser);
		parser.line++;
	}
	return (obj);
}
