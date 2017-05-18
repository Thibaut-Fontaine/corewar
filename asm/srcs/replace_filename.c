/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:37:40 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/17 17:52:40 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*replace_filename(char *path)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(path) + 4);
	if (!ft_strchr(path, '.'))
	{
		new = ft_strcpy(new, path);
		ft_strcat(new, ".cor");
	}
	else
	{
		while (path[i] != '.')
		{
			new[i] = path[i];
			i++;
		}
		ft_strcat(new, ".cor");
	}
	return (new);
}
