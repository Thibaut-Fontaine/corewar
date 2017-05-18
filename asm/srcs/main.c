/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:59:31 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/17 18:06:34 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	t_asm		env;
	char		*name;
	int			i;

	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putendl(" <sourcefile.s>");
		return (-1);
	}
	env = parse(av[1]);
	i = ft_strlen(av[1]) - 2;
	generate_bytecode(&env, name = replace_filename(av[1]));
	free(name);
	free_asm(&env);
	return (0);
}
