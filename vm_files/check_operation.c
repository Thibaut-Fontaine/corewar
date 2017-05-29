/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:25:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/23 22:01:21 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define LIVE		0
#define LD			1
#define ST			2
#define ADD			3
#define SUB 		4
#define AND 		5
#define OR 			6
#define XOR 		7
#define ZJMP 		8
#define LDI 		9
#define STI 		10
#define FORK 		11
#define LLD 		12
#define LLDI 		13
#define LFORK 		14
#define AFF 		15


int **get_ref_tab(void)
{
	int		**tab;

	tab = (int **)malloc(sizeof(int *) * 16);

	tab[LIVE]	= (int[]){0, 0x01000000, 4};
	tab[LD] 	= (int[]){1, 0x06010000, 4};
	tab[ST]		= (int[]){1, 0x01050000, 0};
	tab[ADD]	= (int[]){1, 0x01010100, 0};
	tab[SUB]	= (int[]){1, 0x01010100, 0};
	tab[AND]	= (int[]){1, 0x07070100, 4};
	tab[OR]		= (int[]){1, 0x07070100, 4};
	tab[XOR]	= (int[]){1, 0x07070100, 4};
	tab[ZJMP]	= (int[]){0, 0x10000000, 2};
	tab[LDI]	= (int[]){1, 0x07030100, 2};
	tab[STI]	= (int[]){1, 0x01070300, 2};
	tab[FORK]	= (int[]){0, 0x10000000, 2};
	tab[LLD]	= (int[]){1, 0x06010000, 4};
	tab[LLDI]	= (int[]){1, 0x07030100, 2};
	tab[LFORK]  = (int[]){0, 0x10000000, 2};
	tab[AFF]	= (int[]){1, 0x01000000, 0};

	return (tab);
}

static int check_arg(int coding_int, int mask, int offset)
{
	int		arg;
	int		ref;

	arg = coding_int << offset * 8;
	arg = coding_int >> 3 * 8;
	ref = mask << offset * 8;
	ref = mask >> (3 * 8);
	return (arg & mask);
}

static int convert(char byte)
{
	int ret;
	int offset;
	char tmp;

	ret = 0;
	offset = 3;
	while (offset)
	{
		tmp = byte >> (offset * 2);
		if (tmp == 3)
			tmp++;
		ret = ret + (tmp << (offset * 8));
		offset--;
	}
	return (ret);
}

static int check_args(const char coding_byte, int mask)
{
	int		offset;
	int		coding_int;
	int		ret;

	coding_int = convert(coding_byte);
	offset = 0;
	while ((ret = check_arg(coding_int, mask, offset)))
	{
		if (!ret)
			return (0);
		offset++;
	}
	return (1);
}

static int count_args(char byte)
{
	int args;

	args = 4;
	while (byte % 4 == 0)
	{
		args--;
		byte = byte / 4;
	}
	return (args);
}
/*
static int extract_arg(char *arg, int coding_byte, int **tab)
{
	do stuff
}

static int extract_type(char *arg, int coding_byte, int **tab)
{
	do stuff
}
*/
static void get_args(t_instruct *instruct, char *opcode, char coding_byte, int **tab)
{
	int n_args;
	int i;

	n_args = count_args(coding_byte);
	instruct->opcode = *opcode;
	instruct->args = (int *)malloc(sizeof(int) * (n_args + 1));
	instruct->types = (int *)malloc(sizeof(int) * (n_args + 1));

	i = 0;
	opcode += 2;
	while (i < n_args)
	{
//		instruct->args[i] = extract_arg(opcode, coding_byte, tab);
//		instruct->types[i] = extract_type(opcode, coding_byte, tab);
		i++;
	}
	instruct->args[i] = 0;
	instruct->types[i] = 0;
	(void)tab;
}

t_instruct	*check_operation(char *opcode)
{
	t_instruct	*instruct;
	char		coding_byte;
	int			**tab;

	instruct = (t_instruct *)malloc(sizeof(t_instruct));
	if (*opcode < 1 || *opcode > 16)
		return (0);
	tab = get_ref_tab();
	coding_byte = *(opcode + 1);
	if (tab[*opcode - 1][0])
	{
		if (check_args(coding_byte, tab[*opcode - 1][1]))
			get_args(instruct, opcode, coding_byte, tab);
		else
			return (NULL);
	}
	//else
	//	get_arg(opcode, tab);
	return (NULL);
}
