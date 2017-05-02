/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:27 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

const char	*parse_precision(const char *restrict string, t_specs *specs)
{
	if (*string == '.')
	{
		string++;
		if (ft_isdigit(*string))
		{
			specs->precision = ft_atoi(string);
			while (ft_isdigit(*string))
				string++;
		}
	}
	return (string);
}
