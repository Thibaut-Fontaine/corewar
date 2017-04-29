/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_register.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 22:23:38 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 22:35:13 by mperronc         ###   ########.fr       */
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
	reg = ft_strnew(i + 1);
	ft_strncpy(reg, str, i);
	return (reg);
}
