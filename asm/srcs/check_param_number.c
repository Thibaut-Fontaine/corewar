/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:40:18 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 15:40:19 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_param_number(t_arglist *args, t_parser *parser, int num)
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
	}
}
