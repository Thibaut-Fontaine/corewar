/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:54:45 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/10 19:54:46 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char		*store_arg(t_parser *parser)
{
	int		i;
	char	*str;

	i = 0;
	if (parser->line[parser->current_char] == '-')
		i++;
	while (parser->line[parser->current_char + i] &&
		!ft_iswhitespace(parser->line[parser->current_char + i]) &&
		parser->line[parser->current_char + i] != ',')
		i++;
	str = ft_strsub(parser->line, parser->current_char, i);
	if (!str[0])
	{
		parser->current_char -= 1;
		ft_error("Syntax error", parser);
	}
	parser->current_char += i;
	return (str);
}

t_arglist		*parse_argument(t_parser *parser)
{
	t_arglist	*arg;

	if (!(arg = malloc(sizeof(t_arglist))))
	{
		ft_putendl_fd("failed to malloc argument list", 2);
		exit(-1);
	}
	while (ft_iswhitespace(parser->line[parser->current_char]))
		parser->current_char++;
	if (!parser->line[parser->current_char])
		return (NULL);
	arg->line = parser->current_line;
	arg->type = get_arg_type(parser);
	arg->value = store_arg(parser);
	arg->next = NULL;
	return (arg);
}
