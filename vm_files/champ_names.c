/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 02:10:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 02:29:57 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

/*
** basically save the champions names
*/

void				save_ch_names(t_header ch[MAX_PLAYERS])
{
	static t_header	local[MAX_PLAYERS];
	uint8_t			i;

	i = 0;
	while (ch[i])
	{
		local[i] = ch[i];
	}
}
