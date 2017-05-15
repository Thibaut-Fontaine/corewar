/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:37:05 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/25 15:37:06 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	asm_init(t_asm *obj)
{
	int		i;

	i = 0;
	while (i <= PROG_NAME_LENGTH)
	{
		obj->header.prog_name[i] = '\0';
		i++;
	}
	i = 0;
	while (i <= COMMENT_LENGTH)
	{
		obj->header.comment[i] = '\0';
		i++;
	}
	obj->oplist = NULL;
	obj->labellist = NULL;
}