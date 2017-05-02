/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:39:22 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/03 18:39:46 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

char	*handle_num_precision(char *str, size_t precision)
{
	char *tmp;
	char *pstr;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strnew(precision);
	pstr = str;
	while (precision > ft_strlen(tmp))
	{
		*str = '0';
		str++;
		precision--;
	}
	ft_strcpy(str, tmp);
	free(tmp);
	return (pstr);
}
