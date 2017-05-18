/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:08:37 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:05 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void			check_existing_line(t_parser *parser, t_asm *obj)
{
	int		i;

	i = 1;
	while (parser->line[parser->current_char + i])
	{
		if (ft_iswhitespace(parser->line[parser->current_char + i]))
			i++;
		else
			return ;
	}
	if (!parser->line[parser->current_char + i])
		return ;
	ft_error("Syntax error, expected argument after SEPARATOR_CHAR", parser,
		obj);
}

static void			check_end_line(t_parser *parser, t_asm *obj)
{
	int		i;

	i = 0;
	while (parser->line[parser->current_char + i])
	{
		if (ft_iswhitespace(parser->line[parser->current_char + i]))
			i++;
		else
		{
			parser->current_char += i;
			ft_error("Syntax error, missing SEPARATOR_CHAR", parser,
				obj);
		}
	}
}

t_arglist			*extract_params(t_parser *parser, t_asm *obj)
{
	t_arglist	*arglist;
	t_arglist	*current;

	arglist = NULL;
	while (ft_iswhitespace(parser->line[parser->current_char]))
		parser->current_char++;
	while ((current = parse_argument(parser, obj)))
	{
		add_argument(current, &arglist);
		while ((ft_iswhitespace(parser->line[parser->current_char])))
			parser->current_char++;
		if (parser->line[parser->current_char] != SEPARATOR_CHAR)
		{
			check_end_line(parser, obj);
			break ;
		}
		else
			check_existing_line(parser, obj);
		parser->current_char++;
	}
	return (arglist);
}
