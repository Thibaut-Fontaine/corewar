/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:35:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/28 07:29:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int						check_nflag(int ispresent, int flag)
{
	return ((1 << ispresent) & flag);
}

int						count_champions(int ac, const char *av[], int *i)
{
	int					n;

	*i = 0;
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
					if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > MAX_PLAYERS)
						error(_ERR_BAD_NFLAG)();
					*i |= ft_atoi(av[1]);
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
