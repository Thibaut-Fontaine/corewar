/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 02:01:54 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/15 11:23:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** function used to know if there is the current flag
** return the value associated to this flag, or 1 if there is no associated
** value, or -1 if the flag isn't present.
*/

int		is_there_flag(t_opt flag, int which)
{
	if ((flag.flag & which) != 0)
	{
		if (which == _D_)
			return (flag.nd);
		if (which == _S_)
			return (flag.ns);
		if (which == _V_)
			return (flag.nv);
		return (1);
	}
	else
		return (-1);
}
