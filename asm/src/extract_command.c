/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:32:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 15:14:44 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_command(const char *str)
{
	if (ft_strcmp(str, NAME_CMD_STRING))
		return (ft_strdup(NAME_CMD_STRING));
	else if (ft_strcmp(str, COMMENT_CMD_STRING))
		return (ft_strdup(COMMENT_CMD_STRING));
	else
		return (NULL);
}
