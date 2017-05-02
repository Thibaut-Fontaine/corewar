/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:19:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 18:18:50 by mperronc         ###   ########.fr       */
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
		if (!is_labelchar(str[i]))
			return (NULL);
		i++;
	}
	op = ft_strsub(str, 0, i);
	return (op);
}
