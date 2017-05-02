/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:30:03 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 11:43:51 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fs;

	fs = ft_strnew(len);
	if (fs == NULL)
		return (NULL);
	fs = ft_strncpy(fs, s + start, len);
	fs[len] = 0;
	return (fs);
}
