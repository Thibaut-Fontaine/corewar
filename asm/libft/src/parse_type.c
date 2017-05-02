/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:27 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

const char	*parse_type(const char *restrict string, t_specs *specs)
{
	if ((ft_isupper(*string) && *string != 'X') || *string == 'p')
		specs->length = 'l';
	if (*string == 'd' || *string == 'D' || *string == 'i')
		specs->type = 'd';
	else if (*string == 'o' || *string == 'O')
		specs->type = 'o';
	else if (*string == 'u' || *string == 'U')
		specs->type = 'u';
	else if (*string == 's' || *string == 'S')
		specs->type = 's';
	else if (*string == 'c' || *string == 'C')
		specs->type = 'c';
	else if (*string == 'x' || *string == 'X')
		specs->type = (ft_isupper(*string) ? 'X' : 'x');
	else if (*string == 'p')
		specs->type = 'p';
	else if (*string == '%')
	{
		specs->type = 'c';
		specs->percent = TRUE;
	}
	else
		specs->valid = FALSE;
	string++;
	return (string);
}
