/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:28:56 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/11 17:37:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
