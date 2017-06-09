/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:43 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/09 16:15:44 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

int			extract_dir(t_process *proc, t_instruct *instruct, char *arena,
	int *tab)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (size < tab[3])
	{
		i = i << 8;
		i += *(arena + ((proc->pc + instruct->size + size) % MEM_SIZE));
		size++;
	}
	instruct->size += tab[3];
	return (i);
}
