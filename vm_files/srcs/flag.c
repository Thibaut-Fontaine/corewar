/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 02:01:54 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/26 21:50:29 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** function used to know if there is the current flag
** return the value associated to this flag, or 1 if there is no associated
** value, or -1 if the flag isn't present.
*/

int				is_there_flag(t_opt flag, int which)
{
	if ((flag.flag & which) != 0)
	{
		if (which == _D_ || which == _S_)
			return (flag.n);
		return (1);
	}
	else
		return (-1);
}

/*
** return the flags as an int
*/

int				*flags(void)
{
	static int	flag;

	return (&flag);
}
