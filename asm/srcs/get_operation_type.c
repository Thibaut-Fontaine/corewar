/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:58:42 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/17 17:15:51 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_operation_type(char *str, t_parser *parser)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(str, parser->param_parser[i].name) == 0)
		{
			parser->current_char += ft_strlen(str);
			return (parser->param_parser[i].opcode);
		}
		i++;
	}
	free(str);
	return (0);
}
