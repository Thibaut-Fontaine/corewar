/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:42:11 by mperronc          #+#    #+#             */
/*   Updated: 2016/02/12 17:22:02 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		start;
	int					end;
	char				*res;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start == ft_strlen(s))
	{
		res = ft_strnew(1);
		return (res);
	}
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	end++;
	res = ft_strsub(s, start, end - start);
	if (res == NULL)
		return (NULL);
	res[end - start] = 0;
	return (res);
}
