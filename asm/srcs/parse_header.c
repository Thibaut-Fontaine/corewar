/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:46:49 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:14 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			parse_header(t_asm *obj, t_parser *parser)
{
	if (!parser->check_name && ft_strstr(parser->line, NAME_CMD_STRING)
		== parser->line)
	{
		parser->current_char += ft_strlen(NAME_CMD_STRING);
		parse_name(obj, parser);
		parser->check_name = 1;
		return (1);
	}
	else if (!parser->check_comment && ft_strstr(parser->line,
		COMMENT_CMD_STRING) == parser->line)
	{
		parser->current_char += ft_strlen(COMMENT_CMD_STRING);
		parse_comment(obj, parser);
		parser->check_comment = 1;
		return (1);
	}
	else
	{
		if (parser->line[parser->current_char] == '.')
			ft_error("invalid command name", parser, obj);
		ft_error("No file name or comment at the beginning of the file",
			parser, obj);
	}
	return (0);
}
