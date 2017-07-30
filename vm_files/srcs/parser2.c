/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:35:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/30 01:34:18 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int						count_champions(int ac, const char *av[], const char **champs)
{
	int					n;

	ft_bzero(champs, sizeof(char *) * MAX_PLAYERS);
	n = ac;
	while (ac > 0)
	{
		if ((*av)[0] == '-' && (*av)[2] == 0)
		{
			if ((*av)[1] == 'n' || (*av)[1] == 's' || (*av)[1] == 'd')
			{
				if (ac <= 1 || ((*av)[1] == 'n' && ac <= 2))
					error(_ERR_USAGE)();
				if ((*av)[1] == 'n')
				{
					if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > MAX_PLAYERS
							|| champs[ft_atoi(av[1]) - 1] != NULL)
						error(_ERR_BAD_NFLAG)();
					champs[ft_atoi(av[1]) - 1] = av[2];
				}
				--n;
				--n;
				--ac;
				++av;
			}
			else if ((*av)[1] == 'g')
				--n;
		}
		--ac;
		++av;
	}
	return (n);
}
