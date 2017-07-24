/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 02:01:54 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/24 18:51:03 by tfontain         ###   ########.fr       */
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
		if (which == _D_)
			return (flag.nd);
		if (which == _S_)
			return (flag.ns);
		if (which == _N_)
			return (flag.nv);
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
