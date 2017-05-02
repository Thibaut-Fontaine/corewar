/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:27 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

const char	*parse_specs(const char *restrict string, t_specs *specs)
{
	const char *restrict start;

	start = string;
	specs->valid = TRUE;
	string++;
	string = parse_flags(string, specs);
	string = parse_width(string, specs);
	string = parse_precision(string, specs);
	string = parse_length(string, specs);
	string = parse_type(string, specs);
	return (specs->valid ? string : string - 1);
}
