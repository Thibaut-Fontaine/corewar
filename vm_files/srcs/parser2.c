/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:35:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/27 18:58:50 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			count_champions(int ac, const char *av[])
{
	int		n;

	n = ac;
	while (ac > 0)
	{
		if ((*av)[0] == '-' && (*av)[2] == 0)
		{
			if ((*av)[1] == 'n' || (*av)[1] == 's' || (*av)[1] == 'd')
			{
				if (ac == 1)
					return (n - 1);
				if ((*av)[1] == 'n')
					ft_atoi(av[1]);
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
