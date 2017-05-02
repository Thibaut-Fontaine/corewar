/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_labeldecl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 21:32:18 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 18:04:05 by mperronc         ###   ########.fr       */
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
	labeldecl = ft_strsub(str, 0, i + 1);
	return (labeldecl);
}
