/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:43 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/18 19:28:05 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	extract_dir(t_process *proc, t_instruct *instruct, char *arena,
	int *tab)
{
	int				size;
	unsigned int	i;

	i = 0;
	size = 0;
	while (size < tab[3])
	{
		i = i << 8;
		i = i | (*(arena + ((proc->pc + instruct->size + size) % MEM_SIZE))
		& 0x000000FF);
		size++;
	}
	instruct->size += tab[3];
	return (tab[3] == 4 ? i : (short)i);
}
