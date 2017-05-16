/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:56:48 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/16 22:26:16 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		remove_com(char **line)
{
	int		i;

	i = 0;
	while ((*line)[i] && (*line)[i] != COMMENT_CHAR)
		i++;
	if ((*line)[i] == COMMENT_CHAR)
	{
		if (!(*line = ft_strsub(*line, 0, i)))
			ft_putendl_fd("Failed to sub comment removing", 2);
	}
}
