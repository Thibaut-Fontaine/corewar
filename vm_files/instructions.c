/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:14:38 by vkim              #+#    #+#             */
/*   Updated: 2017/05/19 12:51:02 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/* Describe possible instructions
** fork in process.c (lfork ?)
** live in another castle
** fork : Another File
** lfork : Another File
** live : AF
** aff : OK
** ld : OK
** ldi : X directs ?
** lld : OK
** lldi : X
** st : OK
** sti : X directs ?
** zjump : OK
** sub : OK
** add : OK
** or : X 4 a 5 instr (registre ou diff_pc + arena)
** and : X 4 a 5 instr
** zor : X 4 a 5 instr
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

void			ft_ld_reg(t_process prc, int dest_num, int reg_num)
{
	*(int *)(&prc.reg[dest_num]) = (int)prc.reg[reg_num];
}

void			ft_ld_val(t_process prc, int reg_num, char *arena, int val)
{
	*(int *)(&prc.reg[reg_num]) = val;
	prc.carry = 1;
	//HOW MODIF CARRY ?
}

void			ft_ldi(t_process prc, int rg, char *arn, int ind1, int ind2)
{
	*(int *)&prc.reg[rg] = (int)arn[arn[prc.pc + (ind1 % IDX_MOD)
		+ prc.pc + (ind2 % IDX_MOD)] % MEM_SIZE];
}


void			ft_lld_pc(t_process prc, int reg_num, char *arena, int pc_diff)
{
	*(int *)(&prc.reg[reg_num]) =
		(int)arena[(prc.pc + pc_diff) % MEM_SIZE];
	prc.carry = 1;
	//HOW MODIF CARRY ?
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

/*void			ft_or(t_process prc, int reg_num1, int reg_num2, int dst)
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
}*/

void			ft_zjmp(t_process prc, char *arena, int index)
{
	if (prc.carry == 1)
		prc.pc = index % MEM_SIZE;
}
