/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:25:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/06/22 19:39:53 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	check_arg(int coding_int, int mask, int offset)
{
	int		arg;
	int		ref;

	arg = coding_int << offset * 8;
	arg = arg >> 3 * 8;
	ref = mask << offset * 8;
	ref = ref >> (3 * 8);
	return (arg & ref);
}

static int	convert(char byte)
{
	int		ret;
	int		offset;
	char	tmp;

	ret = 0;
	offset = 3;
	while (offset)
	{
		tmp = byte >> (offset * 2);
		tmp = tmp & 3;
		if (tmp == 3)
			tmp++;
		ret = ret + (tmp << (offset * 8));
		offset--;
	}
	return (ret);
}

static int	check_coding_byte(t_instruct *instruct, const char coding_byte, int *tab)
{
	int		offset;
	int		coding_int;
	int		ret;

	instruct->types = (int *)malloc(sizeof(int) * (tab[2] + 1));
	coding_int = convert(coding_byte);
	offset = 0;
	while ((ret = check_arg(coding_int, tab[1], offset)))
	{
		instruct->types[offset] = ret;
		offset++;
	}
	if (offset == tab[2])
		return (1);
	return (0);
}

static void		fill_instruction(char *arena, t_process *proc, t_instruct *instruct,
	int **tab)
{
	unsigned char c_byte;

	c_byte = *(arena + ((proc->pc + 1) % MEM_SIZE));
	if (tab[*(arena + (proc->pc % MEM_SIZE)) - 1][0])
	{
		if (check_coding_byte(instruct, c_byte, tab[*(arena +
			(proc->pc % MEM_SIZE)) - 1]))
		{
			instruct->size = 2;
			get_args(proc, arena, tab[*(arena +
				(proc->pc % MEM_SIZE)) - 1], instruct);
		}
		else
			instruct = NULL;
	}
	else
	{
		instruct->size = 1;
		instruct->types[0] = 1;
		get_args(proc, arena, tab[*(arena +
			(proc->pc % MEM_SIZE)) - 1], instruct);
	}
}

t_instruct	*check_operation(char *arena, t_process *proc, int **tab)
{
	t_instruct	*instruct;

	if (!(instruct = (t_instruct *)malloc(sizeof(t_instruct))))
		exit_perror("Malloc error");
	if (*(arena + proc->pc) < 1 || *(arena + proc->pc) > 16)
		return (NULL);
	instruct->opcode = *(arena + proc->pc);
	fill_instruction(arena, proc, instruct, tab);
	return (instruct);
}