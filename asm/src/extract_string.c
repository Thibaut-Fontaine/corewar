/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:55:19 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 22:25:56 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_string(char *str)
{
	int		i;
	char	*string;

	i = 1;
	while (str[i] && str[i] != STRING_CHAR)
		i++;
	string = ft_strnew(i);
	ft_strncpy(string, str + 1, i - 1);
	return (string);
}
