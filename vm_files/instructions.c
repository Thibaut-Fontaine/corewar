/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:14:38 by vkim              #+#    #+#             */
/*   Updated: 2017/05/18 16:18:56 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/* Describe possible instructions
**fork in process.c (lfork ?)
**live in another castle
*/

void			ft_aff(t_process prc, int reg_num)
{
	ft_putchar(((int)prc.reg[reg_num]) % 256);
}

void			ft_st_pc(t_process prc, int reg_num, char *arena, int pc_diff)
{
	*(int *)(&arena[(prc.pc + (pc_diff % IDX_MOD) % MEM_SIZE)]) =
		(int)prc.reg[reg_num];
}

void			ft_st_reg(t_process prc, int reg_num, int dest_num)
{
	*(int *)(&prc.reg[dest_num]) = (int)prc.reg[reg_num];
}

void			ft_ld_pc(t_process prc, int reg_num, char *arena, int pc_diff)
{
	*(int *)(&prc.reg[reg_num]) =
		(int)arena[(prc.pc + (pc_diff % IDX_MOD)) % MEM_SIZE];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_lld_pc(t_process prc, int reg_num, char *arena, int pc_diff)
{
	*(int *)(&prc.reg[reg_num]) =
		(int)arena[(prc.pc + pc_diff) % MEM_SIZE];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_ld_reg(t_process prc, int dest_num, int reg_num)
{
	*(int *)(&prc.reg[dest_num]) = (int)prc.reg[reg_num];
}

void			ft_add(t_process prc, int reg_num1, int reg_num2, int dst)
{
	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] + (int)prc.reg[reg_num2];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_sub(t_process prc, int reg_num1, int reg_num2, int dst)
{
	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] - (int)prc.reg[reg_num2];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_and(t_process prc, int reg_num1, int reg_num2, int dst)
{
	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] & (int)prc.reg[reg_num2];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_or(t_process prc, int reg_num1, int reg_num2, int dst)
{
	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] | (int)prc.reg[reg_num2];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_xor(t_process prc, int reg_num1, int reg_num2, int dst)
{
	*(int *)(&prc.reg[dst]) = (int)prc.reg[reg_num1] ^ (int)prc.reg[reg_num2];
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

/*
 **zjump
 **ldi
 **lldi
*/
