/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:11:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/18 19:31:31 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			is_valid_reg(int reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	return (1);
}

int			store_at(char *arena, const int i, const int val)
{
	arena[mod((i + 0), MEM_SIZE)] = ((char*)(&val))[3];
	arena[mod((i + 1), MEM_SIZE)] = ((char*)(&val))[2];
	arena[mod((i + 2), MEM_SIZE)] = ((char*)(&val))[1];
	arena[mod((i + 3), MEM_SIZE)] = ((char*)(&val))[0];
	return (val);
}

int			extract_at(char *arena, int i)
{
	int	val;

	((char*)(&val))[3] = arena[mod((i + 0), MEM_SIZE)];
	((char*)(&val))[2] = arena[mod((i + 1), MEM_SIZE)];
	((char*)(&val))[1] = arena[mod((i + 2), MEM_SIZE)];
	((char*)(&val))[0] = arena[mod((i + 3), MEM_SIZE)];
	return (val);
}

int			swap_32int(int num)
{
	return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) |
	((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}

void		free_instruction(t_instruct *instruct)
{
	if (instruct)
	{
		free(instruct->args);
		free(instruct->types);
		free(instruct);
	}
}

int			count_live(int reset)
{
	static uint	live = 0;
	uint		tmp;

	tmp = live;
	if (reset)
		live = 0;
	else
		++live;
	return (tmp);
}

/*
** functions who returns the pt where to write in all case (can be IND or REG)
** or return a value to read (DIR, INT or REG)
*/

int			op_value(t_process *proc, char *arena, int n, int idx)
{
	if (proc->instruct->types[n] == T_DIR)
		return (proc->instruct->args[n]);
	if (proc->instruct->types[n] == T_REG)
	{
		if (!is_valid_reg(proc->instruct->args[n]))
			return (0);
		return (proc->reg[proc->instruct->args[n] - 1]);
	}
	if (proc->instruct->types[n] == T_IND)
	{
		if (idx == 0)
			return (extract_at(arena, proc->pc + proc->instruct->args[n]));
		else
			return (extract_at(arena, proc->pc +
						(mod(proc->instruct->args[n], IDX_MOD))));
	}
	return (0);
}

/*
** check if each arg who is a register is between 1 and REG_NUMBER.
*/

int			check_register(t_instruct *i)
{
	if (i->types[0] == T_REG && !is_valid_reg(i->args[0]))
		return (0);
	if (i->types[1] == T_REG && !is_valid_reg(i->args[1]))
		return (0);
	if (i->types[2] == T_REG && !is_valid_reg(i->args[2]))
		return (0);
	return (1);
}

inline int	mod(int n, int d)
{
	n %= d;
	return (n < 0 ? n + d : n);
}
