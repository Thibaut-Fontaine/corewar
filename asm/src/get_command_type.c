/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:42:35 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/02 20:26:29 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"

int		get_command_type(const char *source)
{
	if (!(ft_strcmp(source, ".name")))
		return (NAME_COMMENT);
	else if (!(ft_strcmp(source, ".comment")))
		return (CMD_COMMENT);
	else
		return (INVALID);
}
