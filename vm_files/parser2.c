/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:35:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/15 14:22:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"

int			count_champions(int argc, const char *argv[])
{
	int		argcrem;

	argcrem = argc;
	while (argc)
	{
		if (ft_strequ(*argv, "-a") || ft_strequ(*argv, "-b")
				|| ft_strequ(*argv, "-n") || ft_strequ(*argv, "--stealth"))
			--argcrem;
		else if (**argv == '-' && (*argv)[2] == '\0' && ((*argv)[1] == 'v'
					|| (*argv)[1] == 's' || (*argv)[1] == 'd'))
		{
			if (*(argv + 1))
			{
				--argcrem;
				--argcrem;
				++argv;
				--argc;
			}
			else
				--argcrem;
		}
		++argv;
		--argc;
	}
	return (argcrem);
}
