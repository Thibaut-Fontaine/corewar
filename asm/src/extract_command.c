/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:32:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 16:56:19 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

int			*extract_command(const char *str)
{
	if (ft_strcmp(str, NAME_CMD_STRING) == 0)
		return (CMD_NAME);
	else if (ft_strcmp(str, COMMENT_CMD_STRING))
		return (CMD_COMMENT);
	else
		return (INVALID);
}
