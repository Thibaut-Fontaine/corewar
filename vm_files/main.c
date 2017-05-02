/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:22:42 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/02 18:12:54 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vm.h"
#include <stdio.h> //

int			main(int argc, const char *argv[])
{
	int		tmp;
	t_file *s;
	int		i;

	s = open_file(argv[1], &tmp);
	i = 0;
	/*while (i <= tmp)
	{
		if (i % 16 == 0)
		{
			printf("%07x ", i);
			fflush(stdout);
		}
		ft_putstr(ft_bytohex(s[i], TRUE));
		ft_putchar((i + 1) % 16 == 0 ? '\n' : ' ');
		++i;
	}*/
	return (0);
}
