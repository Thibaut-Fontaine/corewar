/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:51:48 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/17 18:21:40 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_asm(t_asm *tasm)
{
	if (tasm)
	{
		if (tasm->labellist)
			free_labellist(tasm->labellist);
		if (tasm->oplist)
			free_oplist(tasm->oplist);
		if (tasm->header)
			free(tasm->header);
		if (tasm->optab)
			free_optab(tasm->optab);
	}
}
