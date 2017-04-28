/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitoby.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:30:08 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/22 17:48:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_pow(int x, unsigned int y)
{
	int			tmp;

	if (y == 0)
		return (1);
	tmp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp);
	else
		return (x * tmp * tmp);
}

char			ft_bitoby(unsigned int n)
{
	int			k;
	int			i;
	int			tmp;

	k = 0;
	i = 0;
	while (n != 0)
	{
		tmp = n % 10;
		n /= 10;
		k += tmp * ft_pow(2, i);
		++i;
	}
	return (k);
}
