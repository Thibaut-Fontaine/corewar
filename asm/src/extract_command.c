/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:32:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 22:45:13 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_command(const char *str)
{
	if (ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (ft_strdup(NAME_CMD_STRING));
	else if (ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (ft_strdup(COMMENT_CMD_STRING));
	else
		return (NULL);
}

void	test_extract_command()
{
	assert_equals(".name", extract_command(".name"));
	assert_equals(".command", extract_command(".command"));
	assert_equals(".name", extract_command(".name   \"toto\""));
	assert_equals(NULL, extract_command(".nametoto"));
	assert_equals(NULL, extract_command("name"));
	assert_equals(NULL, extract_command(NULL));
}
