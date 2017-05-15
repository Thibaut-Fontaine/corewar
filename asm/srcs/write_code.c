/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 01:46:52 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/15 13:04:23 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_code(int fhandle, t_asm *tasm)
{
	t_oplist	*iter;

	iter = tasm->oplist;
	while (iter != NULL)
	{
		write_op(fhandle, iter, tasm);
		iter = iter->next;
	}
}