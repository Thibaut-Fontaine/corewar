/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:47:37 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/18 19:28:11 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	set_wait(char opcode)
{
	static int wait[] =
	{10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25,
		800, 10, 50, 1000, 2};

	return (wait[opcode - 1]);
}

void		get_args(t_process *proc, char *arena, int *tab,
	t_instruct *instruct)
{
	int	i;

	i = 0;
	while (i < tab[2])
	{
		if (instruct->types[i] == T_REG)
			instruct->args[i] = extract_reg(proc, instruct, arena);
		else if (instruct->types[i] == T_DIR)
			instruct->args[i] = extract_dir(proc, instruct, arena, tab);
		else if (instruct->types[i] == T_IND)
			instruct->args[i] = extract_ind(proc, instruct, arena);
		i++;
	}
	proc->wait = set_wait(instruct->opcode);
}
