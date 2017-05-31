/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 02:10:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/31 03:53:51 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

t_champion				*get_champion(void)
{
	static t_champion	local[MAX_PLAYERS];

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
		get_champion()[i].live = 0;
	}
}
