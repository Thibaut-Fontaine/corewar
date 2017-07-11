/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:51 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/11 17:32:20 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			extract_ind(t_process *proc, t_instruct *instruct, char *arena)
{
	int		adr;

	adr = 0 | (*(arena + ((proc->pc + instruct->size) % MEM_SIZE)) * (1 << 8)
	& 0x000000FF);
	adr = adr | (*(arena + ((proc->pc + instruct->size + 1) % MEM_SIZE))
	& 0x000000FF);
	instruct->size += 2;
	return (adr);
}
