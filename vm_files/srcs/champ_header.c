/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 02:10:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/18 19:27:57 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_champion				*get_champion(void)
{
	static t_champion	local[MAX_PLAYERS];

	return (local);
}

int						n_champ(int n)
{
	static int			local = -1;

	if (local == -1)
		local = n;
	return (local);
}

void					save_ch_names(t_header ch[MAX_PLAYERS])
{
	uint8_t				i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_strcpy(get_champion()[i].prog_name, ch[i].prog_name);
		ft_strcpy(get_champion()[i].comment, ch[i].comment);
		++i;
	}
}
