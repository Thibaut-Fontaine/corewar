/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:22:42 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/08 02:57:24 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

int			main(int argc, const char *argv[])
{
	t_argv	*all;

	all = parse(argc, argv);
	//printf("Flag A -> %d\n", is_there_flag(all->f, _A_));
	//printf("Flag D -> %d\n", is_there_flag(all->f, _D_));
	//printf("Flag S -> %d\n", is_there_flag(all->f, _S_));
	//printf("Flag V -> %d\n", is_there_flag(all->f, _V_));
	//printf("Flag B -> %d\n", is_there_flag(all->f, _B_));
	//printf("Flag N -> %d\n", is_there_flag(all->f, _N_));
	//printf("Flag STEALTH -> %d\n", is_there_flag(all->f, _STEALTH_));
	write(1, all->arena, MEM_SIZE);
	return (0);
}
