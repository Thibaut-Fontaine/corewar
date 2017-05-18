/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:40:18 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:03 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_param_number(t_arglist *args, t_asm *obj,
	t_parser *parser, int num)
{
	int			i;
	t_arglist	*tmp;

	i = 0;
	tmp = args;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i != num)
	{
		ft_putstr_fd("Error : expected ", 2);
		ft_putnbr_fd(num, 2);
		ft_putstr_fd(" arguments at line: ", 2);
		ft_putnbr_fd(parser->current_line, 2);
		write(2, "\n", 1);
		free_asm(obj);
		free_parser(parser);
		exit(-1);
	}
}
