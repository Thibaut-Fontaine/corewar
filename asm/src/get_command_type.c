/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commend_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:42:35 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 16:42:36 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/asm.h"

int		get_command_type(const char *source)
{
	if (!(ft_strcmp(source, ".name")))
		return (CMD_NAME);
	else if (!(ft_strcmp(source, ".comment")))
		return (CMD_COMMENT);
	else
		return (INVALID);
}

