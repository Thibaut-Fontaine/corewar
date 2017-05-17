/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:24:30 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/17 17:24:47 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		free_parser(t_parser *parser)
{
	int		i;

	i = 0;
	if (!parser)
		return ;
	if (parser->line)
		free(parser->line);
	free(parser->param_parser);
}
