/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_labeldecl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:32:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/29 21:52:06 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_asm.h"

char	*extract_labeldecl(const char *str)
{
	int		i;
	char	*labeldecl;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (is_labelchar(str[i]))
			i++;
		else
			return (NULL);
	}
	labeldecl = ft_strnew(i + 1);
	ft_strncpy(labeldecl, str, i);
	return (labeldecl);
}
