/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:06:46 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/04 14:06:47 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"

void	asm_init(t_asm *obj)
{
	if (!(obj->header = malloc(sizeof t_header)))
	{
		obj = NULL:
		return ;
	}
	obj->header->magic = COREWAR_EXEC_MAGIC;
	obj->header->prog_name = NULL;
	obj->header->prog_size = 0;
	obj->header->prog_comment = NULL;
	obj->oplist = NULL;
	obj->labels = NULL;
}