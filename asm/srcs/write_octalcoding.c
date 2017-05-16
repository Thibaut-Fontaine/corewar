/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octalcoding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:54:52 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/16 22:26:19 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char	get_codon(char type)
{
	if (type == T_REG)
		return (1);
	else if (type == T_DIR || type == (T_DIR | T_LAB))
		return (2);
	else if (type == T_IND || type == (T_IND | T_LAB))
		return (3);
	else
		return (0);
}

void		write_octalcoding(int fhandle, t_oplist *op)
{
	char		code;
	int			offset;
	t_arglist	*arg;

	offset = 6;
	code = 0;
	arg = op->args;
	while (arg != NULL)
	{
		code = code | get_codon(arg->type) << offset;
		offset -= 2;
		arg = arg->next;
	}
	write(fhandle, &code, 1);
}
