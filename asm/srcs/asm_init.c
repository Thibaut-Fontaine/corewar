/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:37:05 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:25:58 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	asm_init(t_asm *obj)
{
	int		i;

	i = 0;
	if (!(obj->header = malloc(sizeof(t_header))))
	{
		ft_putendl_fd("failed to malloc header", 2);
		exit (-1);
	}
	obj->header->magic = COREWAR_EXEC_MAGIC;
	while (i <= PROG_NAME_LENGTH)
	{
		obj->header->prog_name[i] = '\0';
		i++;
	}
	i = 0;
	while (i <= COMMENT_LENGTH)
	{
		obj->header->comment[i] = '\0';
		i++;
	}
	obj->oplist = NULL;
	obj->labellist = NULL;
	obj->optab = init_optab();
}
