/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:25:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/23 17:26:14 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define LD_ARGS 	0x06010000
#define ST_ARGS		0x01050000
#define ADD_ARGS	0x01010100
#define SUB_ARGS	0x01010100
#define AND_ARGS	0x07070100
#define OR_ARGS		0x07070100
#define XOR_ARGS	0x07070100
#define LDI_ARGS	0x07030100
#define STI_ARGS	0x01070300
#define LLD_ARGS	0x06010000
#define LLDI_ARGS	0x07030100
#define AFF_ARGS	0x01000000

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


int	*get_ref_tab(void)
{
	int		tab[16];

	tab[LIVE]	= 0;
	tab[LD] 	= LD_ARGS;
	tab[ST]		= ST_ARGS;
	tab[ADD]	= ADD_ARGS;
	tab[SUB]	= SUB_ARGS;
	tab[AND]	= AND_ARGS;
	tab[OR]		= OR_ARGS;
	tab[XOR]	= XOR;
	tab[ZJMP]	= 0;
	tab[LDI]	= LDI_ARGS;
	tab[STI]	= STI_ARGS;
	tab[FORK]	= 0;
	tab[LLD]	= LLD_ARGS;
	tab[LLDI]	= LLDI_ARGS;
	tab[LFORK]  = 0;
	tab[AFF]	= AFF_ARGS;

	return (tab);
}

char	check_operation(char *opcode)
{
	char	coding_byte;
	int		*tab;

	if (*opcode < 1 || *opcode > 16)
		return (0);

	tab = get_ref_tab();
	coding_byte = (tab[*opcode - 1] ? *(opcode + 1) : 0);

	if (coding_byte)
	{
		if (check_args(coding_byte, tab[*opcode - 1]))
		{
			instruct->args = get_args(opcode, coding_byte);
		}
	}
	else
		// recuperer le seul arg

}
