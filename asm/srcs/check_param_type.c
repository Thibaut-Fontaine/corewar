/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:18:17 by jgagnot           #+#    #+#             */
/*   Updated: 2017/07/24 16:46:31 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			expected_type(int type)
{
	int		flag;

	flag = 0;
	if (type & T_REG)
	{
		ft_putstr_fd("register", 2);
		flag = 1;
	}
	if (type & T_DIR)
	{
		if (flag == 1)
			ft_putstr_fd(" or ", 2);
		ft_putstr_fd("direct", 2);
		flag = 1;
	}
	if (type & T_IND)
	{
		if (flag == 1)
			ft_putstr_fd(" or ", 2);
		ft_putstr_fd("indirect", 2);
	}
}

void			check_param_type(t_arglist *arg, int type, t_asm *obj,
	t_parser *parser)
{
	int		i;

	i = arg->type & type;
	if (i == 0)
		param_error(arg, type, obj, parser);
}
