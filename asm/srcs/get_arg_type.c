/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:36:39 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 23:42:57 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_arg_type(t_parser *parser)
{
	if (parser->line[parser->current_char] == DIRECT_CHAR)
	{
		if (parser->line[parser->current_char + 1] == LABEL_CHAR)
		{
			parser->current_char += 2;
			return (T_DIR + T_LAB);
		}
		parser->current_char += 1;
		return (T_DIR);
	}
	else if (parser->line[parser->current_char] == 'r')
	{
		parser->current_char += 1;
		return (T_REG);
	}
	if (parser->line[parser->current_char] == LABEL_CHAR)
	{
		parser->current_char += 1;
		return (T_IND + T_LAB);
	}
	return (T_IND);
}
