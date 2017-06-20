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

/*
int		set_wait2(char opcode)
{
	if (opcode == 10)
		return (25);
	if (opcode == 11)
		return (25);
	if (opcode == 12)
		return (800);
	if (opcode == 13)
		return (10);
	if (opcode == 14)
		return (50);
	if (opcode == 15)
		return (1000);
	if (opcode == 16)
		return (2);
	return (0);
}

int		set_wait(char opcode)
{
	if (opcode == 1)
		return (10);
	if (opcode == 2)
		return (5);
	if (opcode == 3)
		return (5);
	if (opcode == 4)
		return (10);
	if (opcode == 5)
		return (10);
	if (opcode == 6)
		return (6);
	if (opcode == 7)
		return (6);
	if (opcode == 8)
		return (6);
	if (opcode == 9)
		return (20);
	return (set_wait2(opcode));
}
*/

int			set_wait(char opcode)
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
	if (!(instruct->args = (int *)malloc(sizeof(int) * tab[2])))
		exit(-1);
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
	proc->pc = (proc->pc + instruct->size) % MEM_SIZE;
	proc->wait = set_wait(instruct->opcode);
}
