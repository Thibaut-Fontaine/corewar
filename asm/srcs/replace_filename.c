/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:37:40 by mperronc          #+#    #+#             */
/*   Updated: 2017/06/20 17:09:50 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char	*copy_path_upto_slash(char *new, char *path)
{
	char *ptr;

	ptr = path + ft_strlen(path) - 1;
	while (*ptr != '/')
		ptr--;
	ft_strncpy(new, path, ptr - path);
	return (ptr);
}

static void	replace_extension(char *new, char *path)
{
	char *ptr;

	if (ft_strchr(path, '.'))
	{
		ptr = path + ft_strlen(path) - 1;
		while (*ptr != '.')
			ptr--;
		ft_strncpy(new, path, ptr - path);
		ft_strcat(new, ".cor");
	}
	else
	{
		ft_strcat(new, path);
		ft_strcat(new, ".cor");
	}
}

char		*replace_filename(char *path)
{
	char *new;
	char *ptr;

	new = ft_strnew(ft_strlen(path) + 4);
	if (ft_strchr(path, '/'))
	{
		ptr = copy_path_upto_slash(new, path);
		replace_extension(new + ft_strlen(new), ptr);
	}
	else
		replace_extension(new, path);
	return (new);
}
