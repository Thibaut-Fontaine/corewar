/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:55:19 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 16:13:34 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_string(const char *str)
{
	int		i;
	char	*string;

	i = 1;
	while (str[i] && str[i] != STRING_CHAR)
		i++;
	string = ft_strnew(i + 1);
	ft_strncpy(string, str, i);
	ft_strcat(string, "\"");
	return (string);
}
