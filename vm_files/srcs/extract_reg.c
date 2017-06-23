/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_reg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:35 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/22 19:40:01 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			extract_reg(t_process *proc, t_instruct *instruct, char *arena)
{
	int		i;

	i = *(arena + ((proc->pc + instruct->size) % MEM_SIZE));
	instruct->size += 1;
	return (i);
}