/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:27 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static const char	*check_h(const char *restrict string, t_specs *specs)
{
	if (*(string + 1) == 'h')
	{
		specs->length = 'H';
		string += 2;
	}
	else
	{
		specs->length = 'h';
		string++;
	}
	return (string);
}

static const char	*check_l(const char *restrict string, t_specs *specs)
{
	if (*(string + 1) == 'l')
	{
		specs->length = 'L';
		string += 2;
	}
	else
	{
		specs->length = 'l';
		string++;
	}
	return (string);
}

const char			*parse_length(const char *restrict string, t_specs *specs)
{
	if (*string == 'h')
		string = check_h(string, specs);
	else if (*string == 'l')
		string = check_l(string, specs);
	else if (*string == 'j')
	{
		specs->length = 'j';
		string++;
	}
	else if (*string == 'z')
	{
		specs->length = 'z';
		string++;
	}
	return (string);
}
