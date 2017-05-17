/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:18:17 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/17 14:18:18 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_param_type(t_arglist *arg, int type)
{
	if (type == T_REG && arg->type != T_REG)
		param_error(arg, "register");
	if (type == T_DIR && !(arg->type == T_DIR || arg->type == T_DIR + T_LAB))
		param_error(arg, "direct");
	if (type == T_IND && !(arg->type == T_IND || arg->type == T_IND + T_LAB))
		param_error(arg, "indirect");
}
