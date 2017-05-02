/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_specs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:26 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	init_specs(t_specs *specs)
{
	specs->data = NULL;
	specs->wdata = NULL;
	specs->minus = FALSE;
	specs->plus = FALSE;
	specs->space = FALSE;
	specs->sharp = FALSE;
	specs->zero = FALSE;
	specs->pointer = FALSE;
	specs->width = 0;
	specs->precision = 0;
	specs->length = '*';
	specs->type = '*';
	specs->percent = FALSE;
	specs->valid = FALSE;
	specs->nullchar = FALSE;
}
