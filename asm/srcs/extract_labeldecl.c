/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_labeldecl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:17:03 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:05 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		extract_labeldecl(t_labellist **labellist, t_asm *obj,
	t_parser *parser)
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
			free_asm(obj);
			free_parser(parser);
			exit(-1);
		}
		add_label_to_list(labellist, obj, parser, name);
		parser->current_char += i + 1;
	}
}
