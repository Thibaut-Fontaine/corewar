/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:52:10 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/17 18:52:11 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_empty_obj(t_oplist *oplist, t_asm *obj, t_parser *parser)
{
	if (oplist)
		return ;
	ft_putendl_fd("Error: no operation in file", 2);
	free_asm(obj);
	free_parser(parser);
	exit(-1);
}
