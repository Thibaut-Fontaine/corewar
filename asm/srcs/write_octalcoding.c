/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octalcoding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:54:52 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/11 17:50:55 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_octalcoding(int fhandle, t_oplist *op)
{
	char		code;
	int			offset;
	t_arglist	*arg;

	arg = op->args;
	offset = 6;
	while (arg != NULL)
	{
		code = code | (arg->type << offset);
		offset -= 2;
		arg = arg->next;
	}
	write(fhandle, &code, 1);
}
