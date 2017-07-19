/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 02:37:37 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/19 03:42:29 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

float		ft_sqrt(float num)
{
	float		guess;
	float		e;
	float		upperbound;

	guess = 1;
	e = 0.001;
	upperbound = num / guess;
	guess = (upperbound + guess) / 2;
	while (!(guess * guess >= num - e && guess * guess <= num + e))
	{
		upperbound = num / guess;
		guess = (upperbound + guess) / 2;
	}
	return (guess);
}

int			swap_32int(int num)
{
	return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) |
	((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}

int			count_live(int reset)
{
	static unsigned int	live = 0;
	unsigned int		tmp;

	tmp = live;
	if (reset)
		live = 0;
	else
		++live;
	return (tmp);
}

/*
** check if each arg who is a register is between 1 and REG_NUMBER.
*/

int			check_register(t_instruct *i)
{
	if (i->types[0] == T_REG && !is_valid_reg(i->args[0]))
		return (0);
	if (i->types[1] == T_REG && !is_valid_reg(i->args[1]))
		return (0);
	if (i->types[2] == T_REG && !is_valid_reg(i->args[2]))
		return (0);
	return (1);
}

inline int	mod(int n, int d)
{
	n %= d;
	return (n < 0 ? n + d : n);
}
