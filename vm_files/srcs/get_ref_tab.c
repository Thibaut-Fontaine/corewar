/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ref_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:45:12 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/18 19:28:13 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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

static int		*fill_tab(int x, int y, int i, int j)
{
	int *ret;

	ret = (int*)malloc(sizeof(int) * 4);
	ret[0] = x;
	ret[1] = y;
	ret[2] = i;
	ret[3] = j;
	return (ret);
}

int				**get_ref_tab(void)
{
	int	**tab;

	tab = (int **)malloc(sizeof(int *) * 16);
	tab[LIVE] = fill_tab(0, 0x01000000, 1, 4);
	tab[LD] = fill_tab(1, 0x06010000, 2, 4);
	tab[ST] = fill_tab(1, 0x01050000, 2, 0);
	tab[ADD] = fill_tab(1, 0x01010100, 3, 0);
	tab[SUB] = fill_tab(1, 0x01010100, 3, 0);
	tab[AND] = fill_tab(1, 0x07070100, 3, 4);
	tab[OR] = fill_tab(1, 0x07070100, 3, 4);
	tab[XOR] = fill_tab(1, 0x07070100, 3, 4);
	tab[ZJMP] = fill_tab(0, 0x10000000, 1, 2);
	tab[LDI] = fill_tab(1, 0x07030100, 3, 2);
	tab[STI] = fill_tab(1, 0x01070300, 3, 2);
	tab[FORK] = fill_tab(0, 0x10000000, 1, 2);
	tab[LLD] = fill_tab(1, 0x06010000, 2, 4);
	tab[LLDI] = fill_tab(1, 0x07030100, 3, 2);
	tab[LFORK] = fill_tab(0, 0x10000000, 1, 2);
	tab[AFF] = fill_tab(1, 0x01000000, 1, 0);
	return (tab);
}
