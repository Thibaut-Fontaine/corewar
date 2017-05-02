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

char	*extract_command(const char *str)
{
	if (ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		return (ft_strdup(NAME_CMD_STRING));
	else if (ft_strncmp(str, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
		return (ft_strdup(COMMENT_CMD_STRING));
	else
		return (NULL);
}
