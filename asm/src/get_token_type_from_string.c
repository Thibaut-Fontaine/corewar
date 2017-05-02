/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type_from_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:42:20 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 16:42:21 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/asm.h"

int 		get_token_type_from_string(const char *source)
{
	if (is_label_token(source))
		return (LABEL);
	else if (is_reg_token(source))
		return (REG);
	else if (is_token_indir(source))
		return (INDIR);
	else if (is_op_token(source))
		return (OP);
	return(INVALID);
}