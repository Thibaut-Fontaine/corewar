/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_optab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:18:37 by mperronc          #+#    #+#             */
/*   Updated: 2017/07/24 16:38:57 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	***init_optab(void)
{
	char	***optab;

	optab = (char ***)malloc(sizeof(char **) * 18);
	optab[0] = ft_strsplit("0,null,0,0,0,0,0", ',');
	optab[1] = ft_strsplit("1,live,2,0,0,10,4", ',');
	optab[2] = ft_strsplit("2,ld,6:1,1,1,5,4", ',');
	optab[3] = ft_strsplit("3,st,1:5,0,1,5,0", ',');
	optab[4] = ft_strsplit("4,add,1:1:1,1,1,10,0", ',');
	optab[5] = ft_strsplit("5,sub,1:1:1,1,1,10,0", ',');
	optab[6] = ft_strsplit("6,and,7:7:1,1,1,6,4", ',');
	optab[7] = ft_strsplit("7,or,7:7:1,1,1,6,4", ',');
	optab[8] = ft_strsplit("8,xor,7:7:1,1,1,6,4", ',');
	optab[9] = ft_strsplit("9,zjmp,2,0,0,20,2", ',');
	optab[10] = ft_strsplit("10,ldi,7:3:1,0,1,25,2", ',');
	optab[11] = ft_strsplit("11,sti,1:7:3,0,1,25,2", ',');
	optab[12] = ft_strsplit("12,fork,2,0,0,800,2", ',');
	optab[13] = ft_strsplit("13,lld,6:1,1,1,10,4", ',');
	optab[14] = ft_strsplit("14,lldi,7:3:1,1,1,50,2", ',');
	optab[15] = ft_strsplit("15,lfork,2,0,0,1000,2", ',');
	optab[16] = ft_strsplit("16,aff,1,0,1,2,0", ',');
	optab[17] = NULL;
	return (optab);
}
