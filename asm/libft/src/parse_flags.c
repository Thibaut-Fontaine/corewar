/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:27 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

const char	*parse_flags(const char *restrict string, t_specs *specs)
{
	while (*string == '#' || *string == '0' || *string == ' ' ||
			*string == '+' || *string == '-')
	{
		if (*string == '#')
			specs->sharp = TRUE;
		else if (*string == '0')
			specs->zero = TRUE;
		else if (*string == ' ')
			specs->space = TRUE;
		else if (*string == '+')
			specs->plus = TRUE;
		else if (*string == '-')
			specs->minus = TRUE;
		string++;
	}
	if (specs->minus)
		specs->zero = FALSE;
	if (specs->plus)
		specs->space = FALSE;
	return (string);
}
