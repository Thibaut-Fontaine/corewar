/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:42:25 by jgagnot           #+#    #+#             */
/*   Updated: 2017/05/04 14:42:26 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_asm.h"

void		remove_comm(char **line)
{
	int 	i;

	i = 0;
	while ((*line)[i] && (*line)[i] != COMMENT_CHAR)
		i++;
	if ((*line)[i] == COMMENT_CHAR)
	{
		if (!(*line = ft_strsub(*line, 0, i)))
			ft_error("Failed to sub comment removing");
	}
}
