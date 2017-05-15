/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:17:03 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/27 11:17:04 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		extract_labeldecl(t_labellist **labellist, t_parser *parser)
{
	int		i;
	char	*name;

	i = 0;
	while (parser->line[parser->current_char + i] &&
		is_labelchar(parser->line[parser->current_char + i]))
		i++;
	if (parser->line[parser->current_char + i] == LABEL_CHAR)
	{
		if (!(name = ft_strsub(parser->line, parser->current_char, i)))
		{
			ft_putendl_fd("failed to malloc label name", 2);
			exit(-1);
		}
		add_label_to_list(labellist, parser, name);
		parser->current_char += i + 1;
	}
}