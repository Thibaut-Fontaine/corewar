/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_optab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:05:44 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/17 18:21:53 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_optab(char ***optab)
{
	int	i;
	int	j;

	i = 0;
	while (optab[i])
	{
		j = 0;
		while (optab[i][j])
		{
			free(optab[i][j]);
			j++;
		}
		free(optab[i]);
		i++;
	}
	free(optab);
}
