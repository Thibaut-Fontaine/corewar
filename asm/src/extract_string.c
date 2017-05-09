/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:55:19 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 17:26:32 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_string(const char *str)
{
	int		i;
	//int		found;
	char	*string;

	i = 1;
	found = 0;
	if (str[0] != STRING_CHAR)
		ft_error("expected STRING_CHAR at the begining of string");
	while (str[i] && str[i] != COMMENT_CHAR)
	{
		if (str[i] == STRING_CHAR)
			found = 1;
		i++;
	}
	if (!found)
		return (NULL);
	string = ft_strsub(str, 0, i + 1);
	return (string);
}
