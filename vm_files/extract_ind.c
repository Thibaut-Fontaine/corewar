/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:51 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/09 16:15:52 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

int			extract_ind(t_process *proc, t_instruct *instruct, char *arena)
{
	int		adr;
	int		i;
	int		j;

	adr = 0;
	adr += *(arena + ((proc->pc + instruct->size) % MEM_SIZE));
	adr = adr << 8;
	adr += *(arena + ((proc->pc + instruct->size + 1) % MEM_SIZE));
	j = (proc->pc + adr) % MEM_SIZE;
	if (j < 0)
		j = MEM_SIZE - j;
	i = *(arena + j);
	instruct->size += 2;
	return (i);
}
