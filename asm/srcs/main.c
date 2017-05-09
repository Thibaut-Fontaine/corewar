/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:59:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/04/11 11:59:35 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/asm.h"
# include <stdio.h>

int		main(int ac, char **av)
{
	t_asm		env;

	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putendl(" <sourcefile.s>");
		return (-1);
	}
	if (av[1][ft_strlen(av[1]) - 1] != 's'
			|| av[1][ft_strlen(av[1]) - 2] != '.')
		ft_putendl_fd("Invalid file name", 2);
	env = parse(av[1]);
	printf("name = %s, comment = %s\n", env.header.prog_name, env.header.comment);
	while (env.labellist)
	{
		printf("label = %s\n", env.labellist->name);
		env.labellist = env.labellist->next;
	}
	return (0);
}
