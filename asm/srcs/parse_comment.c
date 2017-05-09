/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:48:07 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/04 18:48:10 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/asm.h"

void		parse_comment(t_asm *obj, t_parser *parser)
{
	size_t		j;

	while (ft_iswhitespace(parser->line[parser->current_char]))
		parser->current_char++;
	if (parser->line[parser->current_char] != '"')
		ft_error("Expected double quotes around comment", parser);
	parser->current_char++;
	j = 0;
	while (parser->line[parser->current_char] != '"')
	{
		if (j == COMMENT_LENGTH)
		{
			ft_putendl_fd("Comment to long", 2);
			exit(-1);
		}
		obj->header.comment[j] = parser->line[parser->current_char];
		j++;
		parser->current_char++;
	}
}
