/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:14:38 by vkim              #+#    #+#             */
/*   Updated: 2017/05/17 13:37:17 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/* Describe possible instructions (fork in process.c (lfork ?))*/

void			ft_st_pc(t_process prc, int reg_num, char *arena, int pc_diff)
{
	int			i;
	i = -1;
	while (++i < REG_SIZE)
		arena[(pc_diff + i) % IDX_MOD] = (signed char)(prc.reg[reg_num][i]);
}

void			ft_st_reg(t_process prc, int reg_num, int dest_num)
{
	int			i;
	i = -1;
	while (++i < REG_SIZE)
		prc.reg[dest_num][i] = prc.reg[reg_num][i];
}

void			ft_ld_pc(t_process prc, int reg_num, char *arena, int pc_diff)
{
	int			i;
	i = -1;
	while (++i < REG_SIZE)
		prc.reg[reg_num][i] = arena[(pc_diff + i) % IDX_MOD];
}

void			ft_ld_reg(t_process prc, int dest_num, int reg_num)
{
	int			i;
	i = -1;
	while (++i < REG_SIZE)
		prc.reg[dest_num][i] = prc.reg[reg_num][i];
}

void			ft_add(t_process prc, int reg_num1, int reg_num2, int dst)
{
	int			res;

	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] + (int)prc.reg[reg_num2];
}

void			ft_sub(t_process prc, int reg_num1, int reg_num2, int dst)
{
	int			res;

	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] - (int)prc.reg[reg_num2];
}

void			ft_and(t_process prc, int reg_num1, int reg_num2, int dst)
{
	int			res;

	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] & (int)prc.reg[reg_num2];
	//HOW MODIF CARRY ?
}

void			ft_or(t_process prc, int reg_num1, int reg_num2, int dst)
{
	int			res;

	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] | (int)prc.reg[reg_num2];
	//HOW MODIF CARRY ?
}

void			ft_xor(t_process prc, int reg_num1, int reg_num2, int dst)
{
	int			res;

	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] ^ (int)prc.reg[reg_num2];
	//HOW MODIF CARRY ?
}
/*
 **lld
 **zjump
 **ldi
 **aff
 **live
 **lldi
*/
