/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_register.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 22:23:38 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 15:16:16 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_register(const char *str)
{
	int		i;
	char	*reg;

	i = 1;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (i == 1)
		return (NULL);
	reg = ft_strnew(i + 1);
	ft_strncpy(reg, str, i);
	return (reg);
}
