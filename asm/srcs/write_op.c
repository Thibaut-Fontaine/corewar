/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 01:52:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/16 22:26:19 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_op(int fhandle, t_oplist *op, t_asm *tasm)
{
	static size_t bytes_written = 0;

	write(fhandle, &(op->type), 1);
	if (ft_strcmp(tasm->optab[(int)op->type][OCTALFLAG], "1") == 0)
		write_octalcoding(fhandle, op);
	write_args(fhandle, op, bytes_written, tasm);
	bytes_written += op->size;
}
