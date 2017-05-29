/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:00:55 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/15 11:24:11 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** at each call, return fill arena_pt with the index to place the next champion
** undefined behavior if this function is called more than MAX_PLAYER times.
** return the arena.
*/

char				*generate_memory(char **arena_pt, int n_players)
{
	static char		arena[MEM_SIZE] = {0};
	static int		start = 0;

	if (start < MEM_SIZE)
	{
		*arena_pt = (char*)arena + start;
		start += MEM_SIZE / n_players;
	}
	return (arena);
}

/*
** return 0 to MAX_PLAYERS - 1
*/

int					champ_num(int reset)
{
	static int		ret = -1;

	if (reset == CH_NUM_RESET)
		ret = -1;
	if (ret < MAX_PLAYERS - 1)
		++ret;
	return (ret);
}
