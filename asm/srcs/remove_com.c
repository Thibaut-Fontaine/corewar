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

static char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*fs;

	fs = ft_strnew(len);
	if (fs == NULL)
		return (NULL);
	fs = ft_strncpy(fs, s + start, len);
	fs[len] = 0;
	free(s);
	return (fs);
}

void		remove_com(char **line, t_asm *obj, t_parser *parser)
{
	int		i;

	i = 0;
	while ((*line)[i] && (*line)[i] != COMMENT_CHAR)
		i++;
	if ((*line)[i] == COMMENT_CHAR)
	{
		if (!(*line = ft_strsub_free(*line, 0, i)))
		{
			ft_putendl_fd("Failed to sub comment removing", 2);
			free_asm(obj);
			free_parser(parser);
			exit(-1);
		}
	}
}
