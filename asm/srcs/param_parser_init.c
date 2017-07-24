/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parser_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:26:12 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/24 16:50:27 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			to_remove(char *str)
{
	(void)str;
}

t_param_parser	*param_parser_init(void)
{
	t_param_parser	*tab;

	if (!(tab = malloc(sizeof(t_param_parser) * 17)))
	{
		ft_putendl_fd("failed to malloc param_parser", 2);
		exit(-1);
	}
	tab[0] = (t_param_parser){1, "live", 1, {2, 0, 0}, 1, 4};
	tab[1] = (t_param_parser){2, "ld", 2, {6, 1, 0}, 2, 4};
	tab[2] = (t_param_parser){3, "st", 2, {1, 5, 0}, 2, 0};
	tab[3] = (t_param_parser){4, "add", 3, {1, 1, 1}, 2, 0};
	tab[4] = (t_param_parser){5, "sub", 3, {1, 1, 1}, 2, 0};
	tab[5] = (t_param_parser){6, "and", 3, {7, 7, 1}, 2, 4};
	tab[6] = (t_param_parser){7, "or", 3, {7, 7, 1}, 2, 4};
	tab[7] = (t_param_parser){8, "xor", 3, {7, 7, 1}, 2, 4};
	tab[8] = (t_param_parser){9, "zjmp", 1, {2, 0, 0}, 1, 2};
	tab[9] = (t_param_parser){10, "ldi", 3, {7, 3, 1}, 2, 2};
	tab[10] = (t_param_parser){11, "sti", 3, {1, 7, 3}, 2, 2};
	tab[11] = (t_param_parser){12, "fork", 1, {2, 0, 0}, 1, 2};
	tab[12] = (t_param_parser){13, "lld", 2, {6, 1, 0}, 2, 4};
	tab[13] = (t_param_parser){14, "lldi", 3, {7, 3, 1}, 2, 2};
	tab[14] = (t_param_parser){15, "lfork", 1, {2, 0, 0}, 1, 2};
	tab[15] = (t_param_parser){16, "aff", 1, {1, 0, 0}, 2, 0};
	tab[16] = (t_param_parser){17, NULL, 0, {0, 0, 0}, 0, 0};
	return (tab);
}
