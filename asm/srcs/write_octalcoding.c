/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octalcoding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:54:52 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/15 15:24:07 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
	Performs bitwise operations to generate the coding byte for the operation's
	arguments.

	0b	00	 00   00   00
	   arg1 arg2 arg3  --
	As specified in the assignment's documentation :
		REG argument is 01
		DIR argument is 10
		IND argument is 11

	Example :
	IND, REG 		--> 0b 11 01 00 00
	DIR, DIR, DIR	--> 0b 10 10 10 00
	REG, DIR, IND   --> 0b 01 10 11 00
*/
void	write_octalcoding(int fhandle, t_oplist *op)
{
	char		code;
	int			offset;
	t_arglist	*arg;

	offset = 6;
	code = 0;
	arg = op->args;
	while (arg != NULL)
	{
		code = code | ((arg->type == T_IND ? 3 : arg->type) << offset);
		offset -= 2;
		arg = arg->next;
	}
	write(fhandle, &code, 1);
}
