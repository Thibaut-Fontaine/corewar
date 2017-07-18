/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:35:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/18 19:46:13 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			count_champions(int argc, const char *argv[])
{
	int		n;

	n = argc;
	while (argc > 0)
	{
		if (ft_strequ(*argv, "-a") || ft_strequ(*argv, "-b")
				|| ft_strequ(*argv, "-n") || ft_strequ(*argv, "--stealth"))
			--n;
		else if (**argv == '-' && (*argv)[2] == '\0' && ((*argv)[1] == 'v'
					|| (*argv)[1] == 's' || (*argv)[1] == 'd'))
		{
			if (*(argv + 1))
			{
				n -= 2;
				--argc;
				++argv;
			}
			else
				--n;
		}
		++argv;
		--argc;
	}
	return (n);
}
