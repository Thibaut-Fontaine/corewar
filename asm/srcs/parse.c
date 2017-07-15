/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:50:57 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/15 13:17:58 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		parse_line(t_asm *obj, t_parser *parser)
{
	if (ft_strlen(parser->line) == 0 || parser->line[0] == COMMENT_CHAR)
		return ;
	if (!parser->check_name || !parser->check_comment)
		if (parse_header(obj, parser))
			return ;
	remove_com(&parser->line, obj, parser);
	extract_labeldecl(&obj->labellist, obj, parser);
	while (ft_iswhitespace(parser->line[parser->current_char]))
		parser->current_char++;
	if (!parser->line[parser->current_char])
		return ;
	extract_instruction(&obj->oplist, parser, obj);
}

t_parser		init_parser(void)
{
	t_parser	parser;

	parser.current_line = 1;
	parser.position = 0;
	parser.check_name = 0;
	parser.check_comment = 0;
	parser.param_parser = param_parser_init();
	return (parser);
}

t_asm			parse(char *av)
{
	t_parser	parser;
	t_asm		obj;

	parser = init_parser();
	asm_init(&obj);
	if ((parser.fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl_fd("failed to open file", 2);
		exit(-1);
	}
	while (get_next_line(parser.fd, &parser.line) > 0)
	{
		parser.current_char = 0;
		parse_line(&obj, &parser);
		parser.current_line++;
		free(parser.line);
	}
	check_empty_obj(obj.oplist, &obj, &parser);
	check_labels_error(obj.labellist, obj.oplist, &obj, &parser);
	obj.header->prog_size = parser.position;
	free_parser(&parser);
	return (obj);
}
