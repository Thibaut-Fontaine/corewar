/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:19:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 15:22:30 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_op(const char *str)
{
	int		i;
	char	*op;

	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]))
	{
		if (ft_isalpha(str[i]))
			i++;
		else
			return (NULL);
	}
	op = ft_strnew(i + 1);
	ft_strncpy(op, str, i);
	return (op);
}
