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

# include "../includes/asm.h"
# include <stdio.h>
void		extract_labeldecl(t_labellist *labellist, t_parser *parser, uint32_t position)
{
	int 	i;
	char 	*name;

	i = 0;
	while (parser->line[parser->current_char + i] &&
		is_labelchar(parser->line[parser->current_char + i]))
		i++;
	if (parser->line[parser->current_char + i] == LABEL_CHAR)
	{
		name = ft_strsub(parser->line, parser->current_char, i);
		printf("%s\n", name);
	}
	(void)labellist;
	(void)position;
}
