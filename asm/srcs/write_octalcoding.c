/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octalcoding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:54:52 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/15 14:49:05 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
		code = code | ((arg->type == 4 ? 3 : arg->type) << offset);
		ft_printf("%hhx\n", code);
		offset -= 2;
		arg = arg->next;
	}
	write(fhandle, &code, 1);
}
