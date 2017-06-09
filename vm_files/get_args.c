/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:47:37 by jgagnot           #+#    #+#             */
/*   Updated: 2017/06/09 15:47:39 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

void		get_args(t_process *proc, char *arena, int *tab,
	t_instruct *instruct)
	{
		int 	i;

		i = 0;
		if (!(instruct->args = (int *)malloc(sizeof(int) * tab[2])))
			exit(-1);
		while (i < tab[2])
		{
			if (instruct->types[i] == T_REG)
				instruct->args[i] = extract_reg(proc, instruct, arena);
		//	else if (instruct->types[i] == T_DIR)
		//		instruct->arg[i] = extract_dir(proc, instruct, arena, tab);
		//	else if (instruct->types[i] == T_IND)
		//		instruct->arg[i] = extract_ind(proc, instruct, arena, tab)*/
			i++;
		}
	}
