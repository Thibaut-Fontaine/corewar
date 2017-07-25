/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:35:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/24 21:15:59 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			count_champions(int ac, const char *av[])
{
	int		n;

	n = ac;
	--ac;
	while (ac >= 0)
	{
		printf("%s\n", av[ac]);
		if (av[ac][0] == '-' && av[ac][2] == 0)
		{
			--n;
			if (av[ac][1] == 'n' || av[ac][1] == 's' || av[ac][1] == 'd')
				--ac;
			else if (av[ac][1] == 'g')
			{
			}
		}
		;
		--ac;
	}
	printf("%d\n", n);
	return (n);
}
