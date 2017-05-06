/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:00:55 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/06 05:14:12 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** at each call, return fill arena_pt with the index to place the next champion
** undefined behavior if this function is called more than MAX_PLAYER times.
** return the arena.
*/

const char			*generate_memory(char **arena_pt)
{
	static char		arena[MEM_SIZE] = {0};
	static int		start = 0;

	if (start < MEM_SIZE)
	{
		*arena_pt = (char*)arena + start;
		start += BYTES_PER_PLAYER;
	}
	return (arena);
}

int			champ_num(int reset)
{
	static int		ret = 0;

	if (reset == CH_NUM_RESET)
		ret = 0;
	if (ret < MAX_PLAYERS)
		++ret;
	return (ret);
}
