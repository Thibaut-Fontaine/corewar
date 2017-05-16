/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:59:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:11 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/asm.h"
# include <stdio.h>

int		main(int ac, char **av)
{
	t_asm		env;
	char		*name;

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
	name = ft_strcat(av[1], ".cor");
	generate_bytecode(&env, name);
	return (0);
}
