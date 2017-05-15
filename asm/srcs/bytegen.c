/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytegen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:08:10 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/15 13:04:25 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int argc, char **argv)
{
	t_asm	*tasm;

	if (argc == 2) {
		tasm = make_example_asm();
		generate_bytecode(tasm, argv[1]);
	}
	else {
		ft_putstr_fd("Usage : ./asm [file]", 2);
	}
}
